﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "BaseTestSuite.h"

using namespace WEX::Common;
using namespace WEX::Logging;
using namespace WEX::TestExecution;

class UnpackagedTests : BaseTestSuite
{
    BEGIN_TEST_CLASS(UnpackagedTests)
        TEST_CLASS_PROPERTY(L"Description", L"Windows App SDK Push Notifications test")
        TEST_CLASS_PROPERTY(L"ThreadingModel", L"MTA")
        TEST_CLASS_PROPERTY(L"RunAs:Class", L"RestrictedUser")
        TEST_CLASS_PROPERTY(L"IsolationLevel", L"Class")
        TEST_CLASS_PROPERTY(L"Data:SelfContained", L"{true, false}")
    END_TEST_CLASS()

    TEST_CLASS_SETUP(ClassInit)
    {
        BaseTestSuite::ClassSetup();
        return true;
    }

    TEST_CLASS_CLEANUP(ClassUninit)
    {
        BaseTestSuite::ClassCleanup();
        return true;
    }

    TEST_METHOD_SETUP(MethodInit)
    {
        return true;
    }

    TEST_METHOD_CLEANUP(MethodUninit)
    {
        BaseTestSuite::MethodCleanup();
        return true;
    }

    TEST_METHOD(ChannelRequestUsingNullRemoteId);
    TEST_METHOD(ChannelRequestUsingRemoteId);
    TEST_METHOD(MultipleChannelClose); // Currently failing
    TEST_METHOD(VerifyRegisterAndUnregister);
    TEST_METHOD(VerifyRegisterAndUnregisterAll);
    TEST_METHOD(VerifyUnregisterFails);
    TEST_METHOD(VerifyUnregisterAllFails);
    TEST_METHOD(MultipleRegister);
    TEST_METHOD(VerifyMultipleRegisterAndUnregister);
    TEST_METHOD(VerifyMultipleRegisterAndUnregisterAll);
    TEST_METHOD(VerifyUnregisterTwice);
    TEST_METHOD(VerifyUnregisterAllTwice);
    TEST_METHOD(VerifyUnregisterAndUnregisterAll);
    TEST_METHOD(VerifyForegroundHandlerSucceeds);
    TEST_METHOD(VerifyForegroundHandlerFails);
};
