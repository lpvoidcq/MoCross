#include "MoPd9Render.h"

MO_NAMESPACE_BEGIN

MO_CLASS_IMPLEMENT_INHERITS(FPd9RenderVertexBuffer, FRenderVertexBuffer);

//============================================================
// <T>������Ⱦ���㻺�塣</T>
//============================================================
FPd9RenderVertexBuffer::FPd9RenderVertexBuffer(){
   _bufferId = 0;
}

//============================================================
// <T>������Ⱦ���㻺�塣</T>
//============================================================
FPd9RenderVertexBuffer::~FPd9RenderVertexBuffer(){
}

//============================================================
// <T>���ô�����</T>
//
// @return �������
//============================================================
TResult FPd9RenderVertexBuffer::OnSetup(){
   glGenBuffers(1, &_bufferId);
   MO_FATAL_CHECK(_bufferId != 0, return EFailure,
         "Generate vertex buffer id failure. (buffer_id=%d)", _bufferId);
   glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
   return ESuccess;
}

//============================================================
// <T>�ϴ����ݡ�</T>
//
// @param pData ����ָ��
// @param length ���ݳ���
// @return �������
//============================================================
TResult FPd9RenderVertexBuffer::Upload(TByteC* pData, TInt length){
   // ������
   MO_CHECK(pData, return ENull);
   MO_CHECK(length > 0, return EFailure);
   // �����
   MO_FATAL_CHECK(_bufferId != 0, return EFailure,
         "Buffer id is invalid. (buffer_id=%d)", _bufferId);
   // �ϴ�����
   glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
   _pDevice->CheckError("glBindBuffer", "Bind array buffer. (buffer_id=%d)", _bufferId);
   glBufferData(GL_ARRAY_BUFFER, length, pData, GL_STATIC_DRAW);
   _pDevice->CheckError("glBufferData", "Upload array buffer data. (buffer_id=%d, length=%d, data=0x%08X)", _bufferId, length, pData);
   return ESuccess;
}

//============================================================
// <T>��������</T>
//
// @return �������
//============================================================
TResult FPd9RenderVertexBuffer::Suspend(){
   return ESuccess;
}

//============================================================
// <T>����������</T>
//
// @return �������
//============================================================
TResult FPd9RenderVertexBuffer::Resume(){
   // ���ɱ��
   glGenBuffers(1, &_bufferId);
   MO_FATAL_CHECK(_bufferId != 0, return EFailure,
         "Generate vertex buffer id failure. (buffer_id=%d)", _bufferId);
   // �󶨱��
   glBindBuffer(GL_ARRAY_BUFFER, _bufferId);
   _pDevice->CheckError("glBindBuffer", "Bind array buffer. (buffer_id=%d)", _bufferId);
   // �ϴ�����
   TInt length = _pDataStream->Length();
   TByteC* pData = _pDataStream->MemoryC();
   glBufferData(GL_ARRAY_BUFFER, length, pData, GL_STATIC_DRAW);
   _pDevice->CheckError("glBufferData", "Upload array buffer data. (buffer_id=%d, length=%d, data=0x%08X)", _bufferId, length, pData);
   return ESuccess;
}

//============================================================
// <T>����������</T>
//
// @return �������
//============================================================
TResult FPd9RenderVertexBuffer::Dispose(){
   if(_bufferId != 0){
      TInt size = _stride * _count;
      glDeleteBuffers(size, &_bufferId);
      _bufferId = 0;
   }
   return ESuccess;
}

MO_NAMESPACE_END