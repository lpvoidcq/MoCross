LOCAL_PATH := $(call my-dir)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := LibLzma
LOCAL_SRC_FILES := libLibLzma.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := LibJpeg
LOCAL_SRC_FILES := libLibJpeg.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := LibFreeType
LOCAL_SRC_FILES := libLibFreeType.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoCommon
LOCAL_SRC_FILES := libMoCommon.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoCore
LOCAL_SRC_FILES := libMoCore.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoMath
LOCAL_SRC_FILES := libMoMath.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoFeatureLogger
LOCAL_SRC_FILES := libMoFeatureLogger.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoFeatureInput
LOCAL_SRC_FILES := libMoFeatureInput.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoFeatureGraphic
LOCAL_SRC_FILES := libMoFeatureGraphic.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoFeatureParticle
LOCAL_SRC_FILES := libMoFeatureParticle.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoFeaturePhysics
LOCAL_SRC_FILES := libMoFeaturePhysics.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoFeatureResource
LOCAL_SRC_FILES := libMoFeatureResource.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoFeatureSound
LOCAL_SRC_FILES := libMoFeatureSound.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoEngine
LOCAL_SRC_FILES := libMoEngine.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoEngine2d
LOCAL_SRC_FILES := libMoEngine2d.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoEngine3d
LOCAL_SRC_FILES := libMoEngine3d.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoEngineFace
LOCAL_SRC_FILES := libMoEngineFace.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoEngineRender
LOCAL_SRC_FILES := libMoEngineRender.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoPlatformAndroid
LOCAL_SRC_FILES := libMoPlatformAndroid.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoPlatformOpenGLES2
LOCAL_SRC_FILES := libMoPlatformOpenGLES2.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)
LOCAL_MODULE := MoGameEngine
LOCAL_SRC_FILES := libMoGameEngine.a
include $(PREBUILT_STATIC_LIBRARY)

#------------------------------------------------------------
include $(CLEAR_VARS)

MO_COMPILER_FLAG       := -D_MO_ANDROID -D_MO_X86

LOCAL_MODULE           := libMpCoolLight
LOCAL_ARM_MODE         := arm
LOCAL_CFLAGS           := $(MO_COMPILER_FLAG)
LOCAL_CXXFLAGS         := $(MO_COMPILER_FLAG)
LOCAL_CPPFLAGS         := $(MO_COMPILER_FLAG)
LOCAL_CPP_EXTENSION    := .cpp

#............................................................
LOCAL_C_INCLUDES       := \
   $(LOCAL_PATH)/../../../../../Library/LibJpeg \
   $(LOCAL_PATH)/../../../../../Library/LibLzma \
   $(LOCAL_PATH)/../../../../../Library/LibFreeType \
   $(LOCAL_PATH)/../../../../../Cross/Common/MoCommon \
   $(LOCAL_PATH)/../../../../../Cross/Common/MoCore \
   $(LOCAL_PATH)/../../../../../Cross/Common/MoMath \
   $(LOCAL_PATH)/../../../../../Cross/Feature/MoFeatureLogger \
   $(LOCAL_PATH)/../../../../../Cross/Feature/MoFeatureInput \
   $(LOCAL_PATH)/../../../../../Cross/Feature/MoFeatureGraphic \
   $(LOCAL_PATH)/../../../../../Cross/Feature/MoFeatureParticle \
   $(LOCAL_PATH)/../../../../../Cross/Feature/MoFeaturePhysics \
   $(LOCAL_PATH)/../../../../../Cross/Feature/MoFeatureResource \
   $(LOCAL_PATH)/../../../../../Cross/Feature/MoFeatureSound \
   $(LOCAL_PATH)/../../../../../Cross/Feature/MoFeatureScript \
   $(LOCAL_PATH)/../../../../../Cross/Engine/MoEngine \
   $(LOCAL_PATH)/../../../../../Cross/Engine/MoEngine2d \
   $(LOCAL_PATH)/../../../../../Cross/Engine/MoEngine3d \
   $(LOCAL_PATH)/../../../../../Cross/Engine/MoEngineFace \
   $(LOCAL_PATH)/../../../../../Cross/Engine/MoEngineRender \
   $(LOCAL_PATH)/../../../../../Cross/Platform/MoPlatformAndroid \
   $(LOCAL_PATH)/../../../../../Cross/Platform/MoPlatformOpenGLES2 \
   $(LOCAL_PATH)/../../../../../Cross/Game/MoGameEngine \

#............................................................
LOCAL_SHARED_LIBRARIES := \
   MoGameEngine \
   \
   MoPlatformOpenGLES2 \
   MoPlatformAndroid \
   \
   MoEngineRender \
   MoEngineFace \
   MoEngine3d \
   MoEngine2d \
   MoEngine \
   \
   MoFeatureGraphic \
   MoFeatureParticle \
   MoFeaturePhysics \
   MoFeatureResource \
   MoFeatureSound \
   MoFeatureInput \
   MoFeatureLogger \
   \
   MoMath \
   MoCore \
   MoCommon \
   \
   LibFreeType \
   LibJpeg \
   LibLzma \

#............................................................
LOCAL_SRC_FILES        := \
   \
   ../../MoTestLogic.cpp \
   ../../MainAndroid.cpp \

#............................................................
LOCAL_LDLIBS           := \
   -landroid \
   -llog \
   -lGLESv2 \

#............................................................
include $(BUILD_SHARED_LIBRARY)
