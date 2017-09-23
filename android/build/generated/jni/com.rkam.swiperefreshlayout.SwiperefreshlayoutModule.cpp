/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "com.rkam.swiperefreshlayout.SwiperefreshlayoutModule.h"

#include "AndroidUtil.h"
#include "EventEmitter.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "Proxy.h"
#include "ProxyFactory.h"
#include "TypeConverter.h"
#include "V8Util.h"



#include "com.rkam.swiperefreshlayout.SwipeRefreshProxy.h"

#include "org.appcelerator.kroll.KrollModule.h"

#define TAG "SwiperefreshlayoutModule"

using namespace v8;

namespace com {
namespace rkam {
namespace swiperefreshlayout {


Persistent<FunctionTemplate> SwiperefreshlayoutModule::proxyTemplate;
jclass SwiperefreshlayoutModule::javaClass = NULL;

SwiperefreshlayoutModule::SwiperefreshlayoutModule(jobject javaObject) : titanium::Proxy(javaObject)
{
}

void SwiperefreshlayoutModule::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);
	Local<Function> proxyConstructor = pt->GetFunction(context).ToLocalChecked();
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Swiperefreshlayout"); // use symbol over string for efficiency
	Local<Object> moduleInstance = proxyConstructor->NewInstance(context).ToLocalChecked();
	exports->Set(nameSymbol, moduleInstance);
}

void SwiperefreshlayoutModule::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::KrollModule::dispose(isolate);
}

Local<FunctionTemplate> SwiperefreshlayoutModule::getProxyTemplate(Isolate* isolate)
{
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "GetProxyTemplate");

	javaClass = titanium::JNIUtil::findClass("com/rkam/swiperefreshlayout/SwiperefreshlayoutModule");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Swiperefreshlayout");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(isolate,
		titanium::KrollModule::getProxyTemplate(isolate)
, javaClass, nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate),
		FunctionTemplate::New(isolate, titanium::Proxy::inherit<SwiperefreshlayoutModule>)->GetFunction());

	titanium::ProxyFactory::registerProxyPair(javaClass, *t);

	// Method bindings --------------------------------------------------------

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

// Methods --------------------------------------------------------------------

// Dynamic property accessors -------------------------------------------------


} // swiperefreshlayout
} // rkam
} // com
