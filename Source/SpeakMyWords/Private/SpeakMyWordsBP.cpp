/**
* Copyright(c) 2017 DRAWNZER GAMES -> ANURAG
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*              coolanuragdzxj@gmail.com
*
*/

#include "SpeakMyWordsBP.h"
#include "Engine.h"

#if PLATFORM_ANDROID
#include "../../../ApplicationCore/Public/Android/AndroidApplication.h"
jmethodID USpeakMyWordsBP::ActivityMethod_InitSpeakMyWords;
jmethodID USpeakMyWordsBP::ActivityMethod_SpeakThisSentence;
jmethodID USpeakMyWordsBP::ActivityMethod_SetSpeakingPitch;
jmethodID USpeakMyWordsBP::ActivityMethod_SetSpeakingSpeechRate;
jmethodID USpeakMyWordsBP::ActivityMethod_IsSpeaking;
jmethodID USpeakMyWordsBP::ActivityMethod_SetDefaultLanguage;
jmethodID USpeakMyWordsBP::ActivityMethod_IsSpeakingInitialized;
#endif



//This function is fo initializing the Android's Text To Speech service in Java.
void USpeakMyWordsBP::InitSpeakMywords()
{
#if PLATFORM_ANDROID
	JNIEnv* java_env = FAndroidApplication::GetJavaEnv();
	ActivityMethod_InitSpeakMyWords = FJavaWrapper::FindMethod(java_env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_InitTTS", "()V", true);
	ActivityMethod_SpeakThisSentence = FJavaWrapper::FindMethod(java_env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SpeakThisSentence", "(Ljava/lang/String;)V", true);
	ActivityMethod_SetSpeakingPitch = FJavaWrapper::FindMethod(java_env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetPitch", "(F)V", true);
	ActivityMethod_SetSpeakingSpeechRate = FJavaWrapper::FindMethod(java_env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_SetSpeechRate", "(F)V", true);
	ActivityMethod_IsSpeaking = FJavaWrapper::FindMethod(java_env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_IsSpeaking", "(F)Z", true);
	ActivityMethod_SetDefaultLanguage = FJavaWrapper::FindMethod(java_env, FJavaWrapper::GameActivityClassID, "AndroidThunkJav_SetDefaultLanguage", "()V", true);
	ActivityMethod_IsSpeakingInitialized = FJavaWrapper::FindMethod(java_env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_IsSpeakingInitialized", "()Z", true);
	FJavaWrapper::CallVoidMethod(java_env, FJavaWrapper::GameActivityThis, ActivityMethod_InitSpeakMyWords);
#endif
}

//This function is to speak this sentence.
void USpeakMyWordsBP::SpeakThisSentence(FString Sentence)
{	
#if PLATFORM_ANDROID
	JNIEnv* java_env = FAndroidApplication::GetJavaEnv();
	jstring str = java_env->NewStringUTF(TCHAR_TO_UTF8(*Sentence));
	FJavaWrapper::CallVoidMethod(java_env, FJavaWrapper::GameActivityThis, ActivityMethod_SpeakThisSentence, str);
	java_env->DeleteLocalRef(str);
#endif
}

//This function is to set the pitch rate of speaking.
void USpeakMyWordsBP::SetSpeakingPitch(float pitch)
{
#if PLATFORM_ANDROID
	JNIEnv* java_env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(java_env, FJavaWrapper::GameActivityThis, ActivityMethod_SetSpeakingPitch, pitch);
#endif
}

//This function is to set the speech rate.
void USpeakMyWordsBP::SetSpeakingSpeechRate(float rate)
{
#if PLATFORM_ANDROID
	JNIEnv* java_env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(java_env, FJavaWrapper::GameActivityThis, ActivityMethod_SetSpeakingSpeechRate, rate);
#endif
}

//This function is get to know whether it's currenlty speaking or not.
bool USpeakMyWordsBP::IsSpeaking()
{
	bool result = false;
#if PLATFORM_ANDROID
	JNIEnv* java_env = FAndroidApplication::GetJavaEnv();
	result = FJavaWrapper::CallBooleanMethod(java_env, FJavaWrapper::GameActivityThis, ActivityMethod_IsSpeaking);
#endif
	return result;
}

//This function is get to know whether speaking is initialized or not.
bool USpeakMyWordsBP::IsSpeakingInitialized()
{
	bool result = false;
#if PLATFORM_ANDROID
	JNIEnv* java_env = FAndroidApplication::GetJavaEnv();
	result = FJavaWrapper::CallBooleanMethod(java_env, FJavaWrapper::GameActivityThis, ActivityMethod_IsSpeakingInitialized);
#endif
	return result;
}

//This function is to speaking language to device default language.
void USpeakMyWordsBP::SetToDeviceDefaultlanguage()
{
#if PLATFORM_ANDROID
	JNIEnv* java_env = FAndroidApplication::GetJavaEnv();
	FJavaWrapper::CallVoidMethod(java_env, FJavaWrapper::GameActivityThis, ActivityMethod_SetDefaultLanguage);
#endif
}



