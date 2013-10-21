MY_DIR := $(call my-dir)
LWFK_DIR := $(realpath $(call my-dir)/../../../../../lwfk)

include $(LWFK_DIR)/lwfk/Android.mk
# include $(PVRSDKDIR)/Tools/OGLES2/Build/Android/Android.mk
include $(MY_DIR)/app/Android.mk
