//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabCppBaseModel.h"

namespace PlayFab
{
namespace CloudScriptModels
{

    enum CloudScriptRevisionOption
    {
        CloudScriptRevisionOptionLive,
        CloudScriptRevisionOptionLatest,
        CloudScriptRevisionOptionSpecific
    };

    PLAYFABCPP_API void writeCloudScriptRevisionOptionEnumJSON(CloudScriptRevisionOption enumVal, JsonWriter& writer);
    PLAYFABCPP_API CloudScriptRevisionOption readCloudScriptRevisionOptionFromValue(const TSharedPtr<FJsonValue>& value);
    PLAYFABCPP_API CloudScriptRevisionOption readCloudScriptRevisionOptionFromValue(const FString& value);

    struct PLAYFABCPP_API FEntityKey : public PlayFab::FPlayFabCppBaseModel
    {
        // Unique ID of the entity.
        FString Id;

        // [optional] Entity type. See https://docs.microsoft.com/gaming/playfab/features/data/entities/available-built-in-entity-types
        FString Type;

        FEntityKey() :
            FPlayFabCppBaseModel(),
            Id(),
            Type()
            {}

        FEntityKey(const FEntityKey& src) :
            FPlayFabCppBaseModel(),
            Id(src.Id),
            Type(src.Type)
            {}

        FEntityKey(const TSharedPtr<FJsonObject>& obj) : FEntityKey()
        {
            readFromValue(obj);
        }

        ~FEntityKey();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FScriptExecutionError : public PlayFab::FPlayFabCppBaseModel
    {
        /**
         * [optional] Error code, such as CloudScriptNotFound, JavascriptException, CloudScriptFunctionArgumentSizeExceeded,
         * CloudScriptAPIRequestCountExceeded, CloudScriptAPIRequestError, or CloudScriptHTTPRequestError
         */
        FString Error;

        // [optional] Details about the error
        FString Message;

        // [optional] Point during the execution of the script at which the error occurred, if any
        FString StackTrace;

        FScriptExecutionError() :
            FPlayFabCppBaseModel(),
            Error(),
            Message(),
            StackTrace()
            {}

        FScriptExecutionError(const FScriptExecutionError& src) :
            FPlayFabCppBaseModel(),
            Error(src.Error),
            Message(src.Message),
            StackTrace(src.StackTrace)
            {}

        FScriptExecutionError(const TSharedPtr<FJsonObject>& obj) : FScriptExecutionError()
        {
            readFromValue(obj);
        }

        ~FScriptExecutionError();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FLogStatement : public PlayFab::FPlayFabCppBaseModel
    {
        // [optional] Optional object accompanying the message as contextual information
        FJsonKeeper Data;

        // [optional] 'Debug', 'Info', or 'Error'
        FString Level;

        // [optional] undefined
        FString Message;

        FLogStatement() :
            FPlayFabCppBaseModel(),
            Data(),
            Level(),
            Message()
            {}

        FLogStatement(const FLogStatement& src) :
            FPlayFabCppBaseModel(),
            Data(src.Data),
            Level(src.Level),
            Message(src.Message)
            {}

        FLogStatement(const TSharedPtr<FJsonObject>& obj) : FLogStatement()
        {
            readFromValue(obj);
        }

        ~FLogStatement();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FExecuteCloudScriptResult : public PlayFab::FPlayFabCppResultCommon
    {
        // Number of PlayFab API requests issued by the CloudScript function
        int32 APIRequestsIssued;

        // [optional] Information about the error, if any, that occurred during execution
        TSharedPtr<FScriptExecutionError> Error;

        double ExecutionTimeSeconds;

        // [optional] The name of the function that executed
        FString FunctionName;

        // [optional] The object returned from the CloudScript function, if any
        FJsonKeeper FunctionResult;

        /**
         * [optional] Flag indicating if the FunctionResult was too large and was subsequently dropped from this event. This only occurs if
         * the total event size is larger than 350KB.
         */
        Boxed<bool> FunctionResultTooLarge;

        // Number of external HTTP requests issued by the CloudScript function
        int32 HttpRequestsIssued;

        /**
         * [optional] Entries logged during the function execution. These include both entries logged in the function code using log.info()
         * and log.error() and error entries for API and HTTP request failures.
         */
        TArray<FLogStatement> Logs;
        /**
         * [optional] Flag indicating if the logs were too large and were subsequently dropped from this event. This only occurs if the total
         * event size is larger than 350KB after the FunctionResult was removed.
         */
        Boxed<bool> LogsTooLarge;

        uint32 MemoryConsumedBytes;

        /**
         * Processor time consumed while executing the function. This does not include time spent waiting on API calls or HTTP
         * requests.
         */
        double ProcessorTimeSeconds;

        // The revision of the CloudScript that executed
        int32 Revision;

        FExecuteCloudScriptResult() :
            FPlayFabCppResultCommon(),
            APIRequestsIssued(0),
            Error(nullptr),
            ExecutionTimeSeconds(0),
            FunctionName(),
            FunctionResult(),
            FunctionResultTooLarge(),
            HttpRequestsIssued(0),
            Logs(),
            LogsTooLarge(),
            MemoryConsumedBytes(0),
            ProcessorTimeSeconds(0),
            Revision(0)
            {}

        FExecuteCloudScriptResult(const FExecuteCloudScriptResult& src) :
            FPlayFabCppResultCommon(),
            APIRequestsIssued(src.APIRequestsIssued),
            Error(src.Error.IsValid() ? MakeShareable(new FScriptExecutionError(*src.Error)) : nullptr),
            ExecutionTimeSeconds(src.ExecutionTimeSeconds),
            FunctionName(src.FunctionName),
            FunctionResult(src.FunctionResult),
            FunctionResultTooLarge(src.FunctionResultTooLarge),
            HttpRequestsIssued(src.HttpRequestsIssued),
            Logs(src.Logs),
            LogsTooLarge(src.LogsTooLarge),
            MemoryConsumedBytes(src.MemoryConsumedBytes),
            ProcessorTimeSeconds(src.ProcessorTimeSeconds),
            Revision(src.Revision)
            {}

        FExecuteCloudScriptResult(const TSharedPtr<FJsonObject>& obj) : FExecuteCloudScriptResult()
        {
            readFromValue(obj);
        }

        ~FExecuteCloudScriptResult();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

    struct PLAYFABCPP_API FExecuteEntityCloudScriptRequest : public PlayFab::FPlayFabCppRequestCommon
    {
        // [optional] The entity to perform this action on.
        TSharedPtr<FEntityKey> Entity;

        // The name of the CloudScript function to execute
        FString FunctionName;

        // [optional] Object that is passed in to the function as the first argument
        FJsonKeeper FunctionParameter;

        /**
         * [optional] Generate a 'entity_executed_cloudscript' PlayStream event containing the results of the function execution and other
         * contextual information. This event will show up in the PlayStream debugger console for the player in Game Manager.
         */
        Boxed<bool> GeneratePlayStreamEvent;

        /**
         * [optional] Option for which revision of the CloudScript to execute. 'Latest' executes the most recently created revision, 'Live'
         * executes the current live, published revision, and 'Specific' executes the specified revision. The default value is
         * 'Specific', if the SpecificRevision parameter is specified, otherwise it is 'Live'.
         */
        Boxed<CloudScriptRevisionOption> RevisionSelection;

        // [optional] The specific revision to execute, when RevisionSelection is set to 'Specific'
        Boxed<int32> SpecificRevision;

        FExecuteEntityCloudScriptRequest() :
            FPlayFabCppRequestCommon(),
            Entity(nullptr),
            FunctionName(),
            FunctionParameter(),
            GeneratePlayStreamEvent(),
            RevisionSelection(),
            SpecificRevision()
            {}

        FExecuteEntityCloudScriptRequest(const FExecuteEntityCloudScriptRequest& src) :
            FPlayFabCppRequestCommon(),
            Entity(src.Entity.IsValid() ? MakeShareable(new FEntityKey(*src.Entity)) : nullptr),
            FunctionName(src.FunctionName),
            FunctionParameter(src.FunctionParameter),
            GeneratePlayStreamEvent(src.GeneratePlayStreamEvent),
            RevisionSelection(src.RevisionSelection),
            SpecificRevision(src.SpecificRevision)
            {}

        FExecuteEntityCloudScriptRequest(const TSharedPtr<FJsonObject>& obj) : FExecuteEntityCloudScriptRequest()
        {
            readFromValue(obj);
        }

        ~FExecuteEntityCloudScriptRequest();

        void writeJSON(JsonWriter& writer) const override;
        bool readFromValue(const TSharedPtr<FJsonObject>& obj) override;
    };

}
}
