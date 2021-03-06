#include "MoPd10Core.h"

MO_NAMESPACE_BEGIN

//============================================================
// <T>转换填充模式类型。</T>
//
// @param fillCd 填充模式
// @return 处理结果
//============================================================
D3D10_FILL_MODE RDirectX10::ConvertFillMode(ERenderFillMode fillCd){
   switch(fillCd){
      case ERenderFillMode_Line:
         return D3D10_FILL_WIREFRAME;
      case ERenderFillMode_Fill:
         return D3D10_FILL_SOLID;
   }
   MO_STATIC_FATAL("Convert fill mode failure. (fill=%d)", fillCd);
   return D3D10_FILL_SOLID;
}

//============================================================
// <T>转换剔除模式类型。</T>
//
// @param cullCd 剔除模式
// @return 处理结果
//============================================================
D3D10_CULL_MODE RDirectX10::ConvertCullMode(ERenderCullMode cullCd){
   switch(cullCd){
      case ERenderCullMode_Front:
         return D3D10_CULL_FRONT;
      case ERenderCullMode_Back:
         return D3D10_CULL_BACK;
      case ERenderCullMode_Both:
         return D3D10_CULL_NONE;
   }
   MO_STATIC_FATAL("Convert cull mode failure. (cull=%d)", cullCd);
   return D3D10_CULL_NONE;
}

//============================================================
// <T>转换索引宽度类型。</T>
//
// @param strideCd 索引宽度
// @return 处理结果
//============================================================
DXGI_FORMAT RDirectX10::ConvertIndexStride(ERenderIndexStride strideCd){
   switch(strideCd){
      case ERenderIndexStride_Uint16:
         return DXGI_FORMAT_R16_UINT;
      case ERenderIndexStride_Uint32:
         return DXGI_FORMAT_R32_UINT;
   }
   MO_STATIC_FATAL("Convert index stride failure. (stride=%d)", strideCd);
   return DXGI_FORMAT_UNKNOWN;
}

//============================================================
// <T>解析属性类型。</T>
//
// @param componentType 组件宽度
// @param mask 遮蔽描述
// @return 处理结果
//============================================================
ERenderAttributeFormat RDirectX10::ParseAttrbuteFormat(D3D_REGISTER_COMPONENT_TYPE componentType, TInt mask){
   // 判断位数
   TInt count = 0;
   if(mask & 0x01){
      count++;
   }
   if(mask & 0x02){
      count++;
   }
   if(mask & 0x04){
      count++;
   }
   if(mask & 0x08){
      count++;
   }
   // 解析类型
   switch(componentType){
      case D3D_REGISTER_COMPONENT_UINT32:
         break;
      case D3D_REGISTER_COMPONENT_SINT32:
         break;
      case D3D_REGISTER_COMPONENT_FLOAT32:{
         if(count == 1){
            return ERenderAttributeFormat_Float1;
         }else if(count == 2){
            return ERenderAttributeFormat_Float2;
         }else if(count == 3){
            return ERenderAttributeFormat_Float3;
         }else if(count == 4){
            return ERenderAttributeFormat_Float4;
         }
      }
   }
   MO_STATIC_FATAL("Parse attribtue format failure. (component_type=%d)", componentType);
   return ERenderAttributeFormat_Unknown;
}

//============================================================
// <T>转换属性格式。</T>
//
// @param formatCd 格式
// @return 属性格式
//============================================================
DXGI_FORMAT RDirectX10::ConvertAttrbuteFormat(ERenderAttributeFormat formatCd){
   switch(formatCd){
      case ERenderAttributeFormat_Float1:
         return DXGI_FORMAT_R32_FLOAT;
      case ERenderAttributeFormat_Float2:
         return DXGI_FORMAT_R32G32_FLOAT;
      case ERenderAttributeFormat_Float3:
         return DXGI_FORMAT_R32G32B32_FLOAT;
      case ERenderAttributeFormat_Float4:
         return DXGI_FORMAT_R32G32B32A32_FLOAT;
      case ERenderAttributeFormat_Byte4:
         return DXGI_FORMAT_R8G8B8A8_UINT;
      case ERenderAttributeFormat_Byte4Normal:
         return DXGI_FORMAT_R8G8B8A8_UNORM;
   }
   MO_STATIC_FATAL("Convert attribute format failure. (format=%d)", formatCd);
   return DXGI_FORMAT_UNKNOWN;
}

MO_NAMESPACE_END
