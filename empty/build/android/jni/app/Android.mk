LOCAL_PATH := /
LOCAL_DIR := $(realpath $(call my-dir)/../../../..)
ASSETDIR := ./assets
LWFK_DIR := $(realpath $(call my-dir)/../../../../../../lwfk)

include $(CLEAR_VARS)

LOCAL_MODULE    := Empty

### Add all source file names to be included in lib separated by a whitespace
LOCAL_SRC_FILES := \
				   	$(LOCAL_DIR)/src/app.cpp \
				   	$(LOCAL_DIR)/src/task/titleTask.cpp \
				   	$(LWFK_DIR)/libraries/PVR/Shell/PVRShell.cpp \
				   	$(LWFK_DIR)/libraries/PVR/Shell/API/KEGL/PVRShellAPI.cpp \
				   	$(LWFK_DIR)/libraries/PVR/Shell/OS/Android/PVRShellOS.cpp \
				   	$(LWFK_DIR)/lwfk/lwApp.cpp \
					$(LWFK_DIR)/lwfk/lwCamera.cpp \
					$(LWFK_DIR)/lwfk/lwColor.cpp \
					$(LWFK_DIR)/lwfk/lwEffects.cpp \
					$(LWFK_DIR)/lwfk/lwlog.cpp \
					$(LWFK_DIR)/lwfk/lwMaterial.cpp \
					$(LWFK_DIR)/lwfk/lwMesh.cpp \
					$(LWFK_DIR)/lwfk/lwModel.cpp \
					$(LWFK_DIR)/lwfk/lwRes.cpp \
					$(LWFK_DIR)/lwfk/lwSprite.cpp \
					$(LWFK_DIR)/lwfk/lwRenderState.cpp \
					$(LWFK_DIR)/lwfk/lwTask.cpp \
					$(LWFK_DIR)/lwfk/lwTexture.cpp \
					$(LWFK_DIR)/lwfk/lwTouch.cpp \
					$(LWFK_DIR)/lwfk/lwSoundAndroid.cpp \
					$(LWFK_DIR)/lwfk/lwText.cpp \
					$(LWFK_DIR)/lwfk/lwThread.cpp \
					$(LWFK_DIR)/libraries/soil/SOIL.c \
				   	$(LWFK_DIR)/libraries/soil/image_DXT.c \
				   	$(LWFK_DIR)/libraries/soil/image_helper.c \
				   	$(LWFK_DIR)/libraries/soil/stb_image_aug.c \
				   	$(LWFK_DIR)/libraries/tinyxml2/tinyxml2.cpp \

LOCAL_C_INCLUDES :=	\
				    $(LWFK_DIR)/libraries/PVR/Shell	\
				    $(LWFK_DIR)/libraries/PVR/Shell/API/KEGL	\
				    $(LWFK_DIR)/libraries/PVR/Shell/OS/Android	\
				    $(LWFK_DIR)/libraries/PVR/Builds/Include	\
				    $(LWFK_DIR)/libraries/PVR/Tools	\
				    $(LWFK_DIR)/libraries/PVR/Tools/OGLES2 \
				    $(LWFK_DIR) \
				    $(LOCAL_DIR)/src \
				    $(LWFK_DIR)/libraries \
				    $(LWFK_DIR)/libraries/soil \
				    $(NDKDIR)/sources/cxx-stl/stlport/stlport
				 

LOCAL_CFLAGS := -DBUILD_OGLES2


LOCAL_LDLIBS :=  \
				-llog \
				-landroid \
				-lEGL \
				-lGLESv2

LOCAL_STATIC_LIBRARIES := \
				          android_native_app_glue \
				          ogles2tools 

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)




