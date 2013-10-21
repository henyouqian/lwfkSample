#!/bin/bash

# Version: 051613001

# This is used for debugging APKs. This command should be ran in the root directory of the project
# The name of the apk file is < ProjectName >-debug.apk and inside the bin directory

# Firstly, run ant debug
. build.sh

ant debug

# Get the package name from AndroidManifest.xml
pack=$( cat AndroidManifest.xml | grep package | awk -F\" '{ print $2 }' )

# Get the first occurrence of the Activity
act=$( cat AndroidManifest.xml | grep 'activity android:name' | awk -F\" '{ print $2 }' | head -1 )

# Get the project name and instantiate the apk file path
pname=$act
apk=bin/$pname-debug.apk

# Make sure the execution was successful first
if [ $? -eq 0 ]; then    

	# Check for the APK in bin directory
	if [ -f $apk ]; then
		# If found, install the file
		adb -d install -r $apk

		# Run the apk inside the application
		adb shell am start -n $pack/$pack.$act
		
		# Filter logcat to show the App's logs
		# adb logcat ActivityManager:I $pname:D *:S

		adb logcat lw:I ActivityManager:I *:S
	else
		echo "[ERR] "APK $apk does not exist. > /dev/stderr
	fi
fi
