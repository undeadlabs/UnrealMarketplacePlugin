//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "Core/PlayFabError.h"
#include "Core/PlayFabCloudScriptDataModels.h"
#include "Core/PlayFabSettings.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

namespace PlayFab
{
    class PLAYFABCPP_API UPlayFabCloudScriptAPI
    {
    public:
        DECLARE_DELEGATE_OneParam(FExecuteEntityCloudScriptDelegate, const CloudScriptModels::FExecuteCloudScriptResult&);

        UPlayFabCloudScriptAPI();
        ~UPlayFabCloudScriptAPI();

        int GetPendingCalls() const;
        FString GetBuildIdentifier() const;
        void SetTitleId(const FString& titleId);
        void SetDevSecretKey(const FString& developerSecretKey);

        // ------------ Generated API calls
        /**
         * Cloud Script is one of PlayFab's most versatile features. It allows client code to request execution of any kind of
         * custom server-side functionality you can implement, and it can be used in conjunction with virtually anything.
         * Executes CloudScript with the entity profile that is defined in the request.
         */
        bool ExecuteEntityCloudScript(CloudScriptModels::FExecuteEntityCloudScriptRequest& request, const FExecuteEntityCloudScriptDelegate& SuccessDelegate = FExecuteEntityCloudScriptDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());

    private:
        // ------------ Generated result handlers
        void OnExecuteEntityCloudScriptResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FExecuteEntityCloudScriptDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);

    };
};
