LOCAL_PATH := /
LOCAL_DIR := $(realpath $(call my-dir)/../../../..)
ASSETDIR := ./assets
LWFK_DIR := $(realpath $(call my-dir)/../../../../../../lwfk)

include $(CLEAR_VARS)

LOCAL_MODULE    := Sliders

### Add all source file names to be included in lib separated by a whitespace
LOCAL_SRC_FILES :=  $(LOCAL_DIR)/src/app.cpp \
				   	$(LOCAL_DIR)/src/task/titleTask.cpp

LOCAL_C_INCLUDES :=	$(LWFK_DIR)/libraries/PVR/Shell	\
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


LOCAL_LDLIBS := -llog \
				-landroid \
				-lEGL \
				-lGLESv2 \
				-lOpenSLES \

LOCAL_STATIC_LIBRARIES := android_native_app_glue \
				          lwfk 

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)




