//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "Core/PlayFabEventsDataModels.h"
#include "Core/PlayFabJsonHelpers.h"

using namespace PlayFab;
using namespace PlayFab::EventsModels;

PlayFab::EventsModels::FEntityKey::~FEntityKey()
{

}

void PlayFab::EventsModels::FEntityKey::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (!Id.IsEmpty() == false)
    {
        UE_LOG(LogTemp, Error, TEXT("This field is required: EntityKey::Id, PlayFab calls may not work if it remains empty."));
    }
    else
    {
        writer->WriteIdentifierPrefix(TEXT("Id"));
        writer->WriteValue(Id);
    }

    if (Type.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("Type"));
        writer->WriteValue(Type);
    }

    writer->WriteObjectEnd();
}

bool PlayFab::EventsModels::FEntityKey::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> IdValue = obj->TryGetField(TEXT("Id"));
    if (IdValue.IsValid() && !IdValue->IsNull())
    {
        FString TmpValue;
        if (IdValue->TryGetString(TmpValue)) { Id = TmpValue; }
    }

    const TSharedPtr<FJsonValue> TypeValue = obj->TryGetField(TEXT("Type"));
    if (TypeValue.IsValid() && !TypeValue->IsNull())
    {
        FString TmpValue;
        if (TypeValue->TryGetString(TmpValue)) { Type = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::EventsModels::FEventContents::~FEventContents()
{
    //if (Entity != nullptr) delete Entity;

}

void PlayFab::EventsModels::FEventContents::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (Entity.IsValid())
    {
        writer->WriteIdentifierPrefix(TEXT("Entity"));
        Entity->writeJSON(writer);
    }

    if (!EventNamespace.IsEmpty() == false)
    {
        UE_LOG(LogTemp, Error, TEXT("This field is required: EventContents::EventNamespace, PlayFab calls may not work if it remains empty."));
    }
    else
    {
        writer->WriteIdentifierPrefix(TEXT("EventNamespace"));
        writer->WriteValue(EventNamespace);
    }

    if (!Name.IsEmpty() == false)
    {
        UE_LOG(LogTemp, Error, TEXT("This field is required: EventContents::Name, PlayFab calls may not work if it remains empty."));
    }
    else
    {
        writer->WriteIdentifierPrefix(TEXT("Name"));
        writer->WriteValue(Name);
    }

    if (OriginalId.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("OriginalId"));
        writer->WriteValue(OriginalId);
    }

    if (OriginalTimestamp.notNull())
    {
        writer->WriteIdentifierPrefix(TEXT("OriginalTimestamp"));
        writeDatetime(OriginalTimestamp, writer);
    }

    if (Payload.notNull())
    {
        writer->WriteIdentifierPrefix(TEXT("Payload"));
        Payload.writeJSON(writer);
    }

    if (PayloadJSON.IsEmpty() == false)
    {
        writer->WriteIdentifierPrefix(TEXT("PayloadJSON"));
        writer->WriteValue(PayloadJSON);
    }

    writer->WriteObjectEnd();
}

bool PlayFab::EventsModels::FEventContents::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TSharedPtr<FJsonValue> EntityValue = obj->TryGetField(TEXT("Entity"));
    if (EntityValue.IsValid() && !EntityValue->IsNull())
    {
        Entity = MakeShareable(new FEntityKey(EntityValue->AsObject()));
    }

    const TSharedPtr<FJsonValue> EventNamespaceValue = obj->TryGetField(TEXT("EventNamespace"));
    if (EventNamespaceValue.IsValid() && !EventNamespaceValue->IsNull())
    {
        FString TmpValue;
        if (EventNamespaceValue->TryGetString(TmpValue)) { EventNamespace = TmpValue; }
    }

    const TSharedPtr<FJsonValue> NameValue = obj->TryGetField(TEXT("Name"));
    if (NameValue.IsValid() && !NameValue->IsNull())
    {
        FString TmpValue;
        if (NameValue->TryGetString(TmpValue)) { Name = TmpValue; }
    }

    const TSharedPtr<FJsonValue> OriginalIdValue = obj->TryGetField(TEXT("OriginalId"));
    if (OriginalIdValue.IsValid() && !OriginalIdValue->IsNull())
    {
        FString TmpValue;
        if (OriginalIdValue->TryGetString(TmpValue)) { OriginalId = TmpValue; }
    }

    const TSharedPtr<FJsonValue> OriginalTimestampValue = obj->TryGetField(TEXT("OriginalTimestamp"));
    if (OriginalTimestampValue.IsValid())
        OriginalTimestamp = readDatetime(OriginalTimestampValue);


    const TSharedPtr<FJsonValue> PayloadValue = obj->TryGetField(TEXT("Payload"));
    if (PayloadValue.IsValid() && !PayloadValue->IsNull())
    {
        Payload = FJsonKeeper(PayloadValue);
    }

    const TSharedPtr<FJsonValue> PayloadJSONValue = obj->TryGetField(TEXT("PayloadJSON"));
    if (PayloadJSONValue.IsValid() && !PayloadJSONValue->IsNull())
    {
        FString TmpValue;
        if (PayloadJSONValue->TryGetString(TmpValue)) { PayloadJSON = TmpValue; }
    }

    return HasSucceeded;
}

PlayFab::EventsModels::FWriteEventsRequest::~FWriteEventsRequest()
{

}

void PlayFab::EventsModels::FWriteEventsRequest::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    writer->WriteArrayStart(TEXT("Events"));
    for (const FEventContents& item : Events)
        item.writeJSON(writer);
    writer->WriteArrayEnd();


    writer->WriteObjectEnd();
}

bool PlayFab::EventsModels::FWriteEventsRequest::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    const TArray<TSharedPtr<FJsonValue>>&EventsArray = FPlayFabJsonHelpers::ReadArray(obj, TEXT("Events"));
    for (int32 Idx = 0; Idx < EventsArray.Num(); Idx++)
    {
        TSharedPtr<FJsonValue> CurrentItem = EventsArray[Idx];
        Events.Add(FEventContents(CurrentItem->AsObject()));
    }


    return HasSucceeded;
}

PlayFab::EventsModels::FWriteEventsResponse::~FWriteEventsResponse()
{

}

void PlayFab::EventsModels::FWriteEventsResponse::writeJSON(JsonWriter& writer) const
{
    writer->WriteObjectStart();

    if (AssignedEventIds.Num() != 0)
    {
        writer->WriteArrayStart(TEXT("AssignedEventIds"));
        for (const FString& item : AssignedEventIds)
            writer->WriteValue(item);
        writer->WriteArrayEnd();
    }


    writer->WriteObjectEnd();
}

bool PlayFab::EventsModels::FWriteEventsResponse::readFromValue(const TSharedPtr<FJsonObject>& obj)
{
    bool HasSucceeded = true;

    obj->TryGetStringArrayField(TEXT("AssignedEventIds"), AssignedEventIds);

    return HasSucceeded;
}

