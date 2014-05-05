#ifndef __MO_ER_CORE_H__
#define __MO_ER_CORE_H__
//************************************************************

#ifndef __MO_ER_COMMON_H__
#include "MoErCommon.h"
#endif // __MO_ER_COMMON_H__

#define MO_ER_EFFECT_PARAMETER_MAXCNT 256
#define MO_ER_EFFECT_ATTRIBUTE_MAXCNT 32
#define MO_ER_EFFECT_SAMPLER_MAXCNT   32

MO_NAMESPACE_BEGIN

//============================================================
// <T>Ч��������</T>
//============================================================
enum EEffectParameter{
   // δ֪
   EEffectParameter_Unknown,
   // �任����
   EEffectParameter_VertexInstance,
   EEffectParameter_VertexModelMatrix3x3,
   EEffectParameter_VertexModelMatrix4x4,
   EEffectParameter_VertexViewMatrix4x4,
   EEffectParameter_VertexProjectionMatrix4x4,
   EEffectParameter_VertexViewProjectionMatrix4x4,
   EEffectParameter_VertexModelViewProjectionMatrix3x3,
   EEffectParameter_VertexModelViewProjectionMatrix4x4,
   EEffectParameter_VertexBoneMatrix4x3,
   EEffectParameter_VertexBoneMatrix4x4,
   // �������
   EEffectParameter_VertexCameraPosition,
   EEffectParameter_VertexCameraDirection,
   // ��Դ����
   EEffectParameter_VertexLightModelMatrix4x4,
   EEffectParameter_VertexLightModelViewMatrix4x4,
   EEffectParameter_VertexLightModelViewProjectionMatrix4x4,
   EEffectParameter_VertexLightPosition,
   EEffectParameter_VertexLightDirection,
   //............................................................
   // �������
   EEffectParameter_FragmentCamera,
   EEffectParameter_FragmentCameraPosition,
   EEffectParameter_FragmentCameraDirection,
   // ��Դ����
   EEffectParameter_FragmentLightModelMatrix4x4,
   EEffectParameter_FragmentLightModelViewProjectrionMatrix4x4,
   EEffectParameter_FragmentLightPosition,
   EEffectParameter_FragmentLightDirection,
   EEffectParameter_FragmentLightDepth,
   // ���ʲ���
   EEffectParameter_FragmentShadowMaterial,
   EEffectParameter_FragmentShadowMaterialInv,
   EEffectParameter_FragmentColor,
   EEffectParameter_FragmentAlpha,
   EEffectParameter_FragmentAmbientColor,
   EEffectParameter_FragmentDiffuseColor,
   EEffectParameter_FragmentDiffuseViewColor,
   EEffectParameter_FragmentSpecularColor,
   EEffectParameter_FragmentSpecular,
   EEffectParameter_FragmentSpecularViewColor,
   EEffectParameter_FragmentSpecularView,
   EEffectParameter_FragmentReflectColor,
};

//============================================================
// <T>Ч���������ߡ�</T>
//============================================================
class MO_ER_DECLARE REffectParameter{
public:
   static TResult Parse(TCharC* pValue, EEffectParameter& parameterCd, ERenderShader& shaderCd, ERenderShaderParameterFormat& formatCd);
   static TCharC* Format(EEffectParameter parameterCd);
};

//============================================================
// <T>Ч������������</T>
//============================================================
struct SEffectParameterDescriptor{
public:
   TInt code;
   TCharC* namePtr;
   TInt bindId;
   ERenderShader shaderCd;
   FRenderShaderParameter* parameterPtr;
public:
   SEffectParameterDescriptor(){
      code = -1;
      MO_CLEAR(namePtr);
      bindId = -1;
      shaderCd = ERenderShader_Unknown;
      MO_CLEAR(parameterPtr);
   }
};

//============================================================
// <T>Ч�������������ϡ�</T>
//============================================================
class TEffectParameterDescriptors : public TFixVector<SEffectParameterDescriptor, MO_ER_EFFECT_PARAMETER_MAXCNT>{
public:
   TEffectParameterDescriptors();
public:
   TResult Link(FRenderShaderParameter* pParameter);
};

//============================================================
// <T>Ч�����ԡ�</T>
//============================================================
enum EEffectAttribute{
   EEffectAttribute_Unknown,
   EEffectAttribute_Instance,
   EEffectAttribute_Position,
   EEffectAttribute_Color,
   EEffectAttribute_Coord,
   EEffectAttribute_Normal,
   EEffectAttribute_Binormal,
   EEffectAttribute_Tangent,
   EEffectAttribute_BoneIndex,
   EEffectAttribute_BoneWeight,
};

//============================================================
// <T>Ч�����Թ��ߡ�</T>
//============================================================
class MO_ER_DECLARE REffectAttribute{
public:
   static TResult Parse(TCharC* pValue, EEffectAttribute& attributeCd, ERenderShaderAttributeFormat& formatCd);
   static TCharC* Format(EEffectAttribute attributeCd);
};

//============================================================
// <T>Ч������������</T>
//============================================================
struct SEffectAttributeDescriptor{
public:
   TInt code;
   TCharC* namePtr;
   ERenderVertexFormat formatCd;
   TInt bindIndex;
   TInt bindId;
   FRenderShaderAttribute* attributePtr;
public:
   SEffectAttributeDescriptor(){
      code = -1;
      MO_CLEAR(namePtr);
      formatCd = ERenderVertexFormat_Unknown;
      bindIndex = -1;
      bindId = -1;
      MO_CLEAR(attributePtr);
   }
};

//============================================================
// <T>Ч�������������ϡ�</T>
//============================================================
class TEffectAttributeDescriptors : public TFixVector<SEffectAttributeDescriptor, MO_EG_EFFECT_ATTRIBUTE_MAXCNT>{
public:
   TEffectAttributeDescriptors();
public:
   void Register(TInt code, TCharC* pName, ERenderVertexFormat formatCd);
   TResult Link(FRenderShaderAttribute* pAttribute);
};

//============================================================
// <T>Ч��ȡ�������͡�</T>
//============================================================
enum EEffectSampler{
   EEffectSampler_Diffuse,
   EEffectSampler_Normal,
   EEffectSampler_Specular,
   EEffectSampler_Light,
   EEffectSampler_Environment,
   EEffectSampler_LightDepth,
   EEffectSampler_Count,
};

//============================================================
// <T>Ч��ȡ�������͹��ߡ�</T>
//============================================================
class MO_FG_DECLARE REffectSampler{
public:
   static EEffectSampler Parse(TCharC* pValue, EEffectSampler samplerCd = EEffectSampler_Diffuse);
   static TCharC* Format(EEffectSampler samplerCd);
};

//============================================================
// <T>Ч��ȡ����������</T>
//============================================================
struct SEffectSamplerDescriptor{
public:
   TInt code;
   TCharC* namePtr;
   ERenderSampler samplerCd;
   TInt bindId;
   TInt index;
   FRenderShaderSampler* samplerPtr;
public:
   SEffectSamplerDescriptor(){
      code = -1;
      MO_CLEAR(namePtr);
      samplerCd = ERenderSampler_Unknown;
      bindId = -1;
      index = -1;
      MO_CLEAR(samplerPtr);
   }
};

//============================================================
// <T>Ч��ȡ�����������ϡ�</T>
//============================================================
class TEffectSamplerDescriptors : public TFixVector<SEffectSamplerDescriptor, MO_EG_EFFECT_SAMPLER_MAXCNT>{
public:
   TEffectSamplerDescriptors();
public:
   void Register(TInt code, TCharC* pName, ERenderSampler samplerCd);
   TResult Link(FRenderShaderSampler* pSampler);
   SEffectSamplerDescriptor* FindByBindId(TInt bindId);
};

MO_NAMESPACE_END

//************************************************************
#endif // __MO_ER_CORE_H__