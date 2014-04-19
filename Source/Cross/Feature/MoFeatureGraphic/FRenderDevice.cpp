#include "MoFgRender.h"

MO_NAMESPACE_BEGIN

MO_CLASS_ABSTRACT_IMPLEMENT_INHERITS(FRenderDevice, FDevice);

//============================================================
// <T>构造舞台对象。</T>
//============================================================
FRenderDevice::FRenderDevice(){
   // 创建当前信息
   MO_CLEAR(_pCapability);
   MO_CLEAR(_pProgram);
   _pTextures = MO_CREATE(FRenderTextureCollection);
   // 创建激活信息
   MO_CLEAR(_pActiveProgram);
   MO_CLEAR(_pActiveRenderTarget);
   _pActiveVertexData = MO_CREATE(FBytes);
   _pActiveFragmentData = MO_CREATE(FBytes);
   _pActiveTextures = MO_CREATE(FRenderTextureCollection);
   // 创建统计信息
   _statistics = FRenderStatistics::InstanceCreate();
}

//============================================================
// <T>析构舞台对象。</T>
//============================================================
FRenderDevice::~FRenderDevice(){
   // 释放当前信息
   MO_DELETE(_pTextures);
   // 释放激活信息
   MO_DELETE(_pActiveVertexData);
   MO_DELETE(_pActiveFragmentData);
   MO_DELETE(_pActiveTextures);
}

//============================================================
// <T>配置处理。</T>
//
// @return 处理结果
//============================================================
TResult FRenderDevice::Setup(){
   MO_INFO("Render device setup.");
   // 注册一个设备统计器
   RStatisticsManager::Instance().StatisticsRegister(_statistics);
   return ESuccess;
}

//============================================================
// <T>挂起处理。</T>
//
// @return 处理结果
//============================================================
TResult FRenderDevice::Suspend(){
   // 挂起所有程序
   TInt programCount = _storagePrograms.Count();
   for(TInt n = 0; n < programCount; n++){
      FRenderProgram* pProgram = _storagePrograms.Next();
      pProgram->Suspend();
   }
   // 挂起所有顶点缓冲
   TInt vertexBufferCount = _storageVertexBuffers.Count();
   for(TInt n = 0; n < vertexBufferCount; n++){
      FRenderVertexBuffer* pVertexBuffer = _storageVertexBuffers.Next();
      pVertexBuffer->Suspend();
   }
   // 挂起所有索引缓冲
   TInt indexBufferCount = _storageIndexBuffers.Count();
   for(TInt n = 0; n < indexBufferCount; n++){
      FRenderIndexBuffer* pIndexBuffer = _storageIndexBuffers.Next();
      pIndexBuffer->Suspend();
   }
   // 挂起所有纹理
   TInt textureCount = _storageTextures.Count();
   for(TInt n = 0; n < textureCount; n++){
      FRenderTexture* pTexture = _storageTextures.Next();
      pTexture->Suspend();
   }
   // 挂起所有目标
   TInt targetCount = _storageTargets.Count();
   for(TInt n = 0; n < targetCount; n++){
      FRenderTarget* pTarget = _storageTargets.Next();
      pTarget->Suspend();
   }
   return ESuccess;
}

//============================================================
// <T>继续处理。</T>
//
// @return 处理结果
//============================================================
TResult FRenderDevice::Resume(){
   // 继续所有程序
   TInt programCount = _storagePrograms.Count();
   for(TInt n = 0; n < programCount; n++){
      FRenderProgram* pProgram = _storagePrograms.Next();
      pProgram->Resume();
   }
   // 继续所有顶点缓冲
   TInt vertexBufferCount = _storageVertexBuffers.Count();
   for(TInt n = 0; n < vertexBufferCount; n++){
      FRenderVertexBuffer* pVertexBuffer = _storageVertexBuffers.Next();
      pVertexBuffer->Resume();
   }
   // 继续所有索引缓冲
   TInt indexBufferCount = _storageIndexBuffers.Count();
   for(TInt n = 0; n < indexBufferCount; n++){
      FRenderIndexBuffer* pIndexBuffer = _storageIndexBuffers.Next();
      pIndexBuffer->Resume();
   }
   // 继续所有纹理
   TInt textureCount = _storageTextures.Count();
   for(TInt n = 0; n < textureCount; n++){
      FRenderTexture* pTexture = _storageTextures.Next();
      pTexture->Resume();
   }
   // 继续所有目标
   TInt targetCount = _storageTargets.Count();
   for(TInt n = 0; n < targetCount; n++){
      FRenderTarget* pTarget = _storageTargets.Next();
      pTarget->Resume();
   }
   return ESuccess;
}

//============================================================
// <T>绘制帧开始处理。</T>
//
// @return 处理结果
//============================================================
TResult FRenderDevice::FrameBegin(){
   _statistics->Reset();
   return ESuccess;
}

//============================================================
// <T>绘制帧结束处理。</T>
//
// @return 处理结果
//============================================================
TResult FRenderDevice::FrameEnd(){
   _statistics->Update(ETrue);
   return ESuccess;
}

//============================================================
// <T>绑定顶点流处理。</T>
//
// @param slot 插槽
// @param pStream 数据流
// @return 处理结果
//============================================================
TResult FRenderDevice::BindVertexStream(TInt slot, FRenderVertexStream* pStream){
   MO_CHECK(slot >= 0, return EFailure);
   ERenderVertexFormat formatCd = ERenderVertexFormat_Unknown;
   TInt offset = 0;
   FRenderVertexBuffer* pVertexBuffer = NULL;
   if(pStream != NULL){
      formatCd = pStream->FormatCd();
      offset = pStream->Offset();
      pVertexBuffer = pStream->VertexBuffer();
      MO_CHECK(pVertexBuffer, return ENull);
   }
   TResult resultCd = BindVertexBuffer(slot, pVertexBuffer, offset, formatCd);
   return resultCd;
}

//============================================================
// <T>绑定常量三维矩阵。</T>
//
// @parma shaderCd 渲染类型
// @parma slot 插槽
// @parma matrix 矩阵
// @return 处理结果
//============================================================
TResult FRenderDevice::BindConstMatrix4x3(ERenderShader shaderCd, TInt slot, const SFloatMatrix3d* pMatrix, TInt count){
   MO_CHECK(slot >= 0, return EFailure);
   MO_CHECK(pMatrix, return ENull);
   MO_CHECK(count > 0, return EFailure);
   MO_CHECK(count <= MO_EG_CONST_MATRIX_MAX, return EFailure);
   // 生成数据
   TFloat data[12 * MO_EG_CONST_MATRIX_MAX];
   TFloat* pWriter = data;
   for(TInt n = 0; n < count; n++){
      const SFloatMatrix3d& matrix = pMatrix[n];
      *pWriter++ = matrix.data[0][0];
      *pWriter++ = matrix.data[1][0];
      *pWriter++ = matrix.data[2][0];
      *pWriter++ = matrix.data[3][0];
      *pWriter++ = matrix.data[0][1];
      *pWriter++ = matrix.data[1][1];
      *pWriter++ = matrix.data[2][1];
      *pWriter++ = matrix.data[3][1];
      *pWriter++ = matrix.data[0][2];
      *pWriter++ = matrix.data[1][2];
      *pWriter++ = matrix.data[2][2];
      *pWriter++ = matrix.data[3][2];
   }
   // 提交数据
   TResult resultCd = BindConstData(shaderCd, slot, ERenderShaderConstForamt_Matrix4x3, data, sizeof(TFloat) * 12 * count);
   return resultCd;
}

//============================================================
// <T>绑定常量三维矩阵。</T>
//
// @parma shaderCd 渲染类型
// @parma slot 插槽
// @parma matrix 矩阵
// @return 处理结果
//============================================================
TResult FRenderDevice::BindConstMatrix4x4(ERenderShader shaderCd, TInt slot, const SFloatMatrix3d* pMatrix, TInt count){
   MO_CHECK(slot >= 0, return EFailure);
   MO_CHECK(pMatrix, return ENull);
   MO_CHECK(count > 0, return EFailure);
   MO_CHECK(count <= MO_EG_CONST_MATRIX_MAX, return EFailure);
   // 生成数据
   TFloat data[16 * MO_EG_CONST_MATRIX_MAX];
   TFloat* pWriter = data;
   for(TInt n = 0; n < count; n++){
      const SFloatMatrix3d& matrix = pMatrix[n];
      *pWriter++ = matrix.data[0][0];
      *pWriter++ = matrix.data[1][0];
      *pWriter++ = matrix.data[2][0];
      *pWriter++ = matrix.data[3][0];
      *pWriter++ = matrix.data[0][1];
      *pWriter++ = matrix.data[1][1];
      *pWriter++ = matrix.data[2][1];
      *pWriter++ = matrix.data[3][1];
      *pWriter++ = matrix.data[0][2];
      *pWriter++ = matrix.data[1][2];
      *pWriter++ = matrix.data[2][2];
      *pWriter++ = matrix.data[3][2];
      *pWriter++ = matrix.data[0][3];
      *pWriter++ = matrix.data[1][3];
      *pWriter++ = matrix.data[2][3];
      *pWriter++ = matrix.data[3][3];
   }
   // 提交数据
   TResult resultCd = BindConstData(shaderCd, slot, ERenderShaderConstForamt_Matrix4x4, data, sizeof(TFloat) * 16 * count);
   return resultCd;
}

//============================================================
// <T>绘制实例网格。</T>
//
// @parma pIndexBuffer 顶点索引
// @parma offset 位置
// @parma count 实例个数
// @return 处理结果
//============================================================
TResult FRenderDevice::DrawInstanceTriangles(FRenderIndexBuffer* pIndexBuffer, TInt offset, TInt count){
   MO_CHECK(pIndexBuffer, return ENull);
   MO_CHECK(count > 0, return EFailure);
   TInt stride = pIndexBuffer->InstanceStride();
   TInt instanceOffset = stride * offset;
   TInt instanceSize = stride * count;
   TResult resultCd = DrawTriangles(pIndexBuffer, instanceOffset, instanceSize);
   return resultCd;
}

MO_NAMESPACE_END