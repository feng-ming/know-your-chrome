/*
    This file is part of the Blink open source project.
    This file has been auto-generated by CodeGeneratorV8.pm. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#include "config.h"
#include "V8TestEventConstructor.h"

#include "RuntimeEnabledFeatures.h"
#include "V8TestEventConstructor.h"
#include "bindings/v8/Dictionary.h"
#include "bindings/v8/ScriptController.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8DOMWrapper.h"
#include "core/dom/ContextFeatures.h"
#include "core/page/Frame.h"
#include <wtf/UnusedParam.h>

#if ENABLE(BINDING_INTEGRITY)
#if defined(OS_WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestEventConstructor@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore20TestEventConstructorE[]; }
#endif
#endif // ENABLE(BINDING_INTEGRITY)

namespace WebCore {

#if ENABLE(BINDING_INTEGRITY)
// This checks if a DOM object that is about to be wrapped is valid.
// Specifically, it checks that a vtable of the DOM object is equal to
// a vtable of an expected class.
// Due to a dangling pointer, the DOM object you are wrapping might be
// already freed or realloced. If freed, the check will fail because
// a free list pointer should be stored at the head of the DOM object.
// If realloced, the check will fail because the vtable of the DOM object
// differs from the expected vtable (unless the same class of DOM object
// is realloced on the slot).
inline void checkTypeOrDieTrying(TestEventConstructor* object)
{
    void* actualVTablePointer = *(reinterpret_cast<void**>(object));
#if defined(OS_WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestEventConstructor@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore20TestEventConstructorE[2];
#endif
    if (actualVTablePointer != expectedVTablePointer)
        CRASH();
}
#endif // ENABLE(BINDING_INTEGRITY)

#if defined(OS_WIN)
// In ScriptWrappable, the use of extern function prototypes inside templated static methods has an issue on windows.
// These prototypes do not pick up the surrounding namespace, so drop out of WebCore as a workaround.
} // namespace WebCore
using WebCore::ScriptWrappable;
using WebCore::V8TestEventConstructor;
using WebCore::TestEventConstructor;
#endif
void initializeScriptWrappableForInterface(TestEventConstructor* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::setTypeInfoInObject(object, &V8TestEventConstructor::info);
}
#if defined(OS_WIN)
namespace WebCore {
#endif
WrapperTypeInfo V8TestEventConstructor::info = { V8TestEventConstructor::GetTemplate, V8TestEventConstructor::derefObject, 0, 0, 0, V8TestEventConstructor::installPerContextPrototypeProperties, 0, WrapperTypeObjectPrototype };

namespace TestEventConstructorV8Internal {

template <typename T> void V8_USE(T) { }

static v8::Handle<v8::Value> attr1AttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    TestEventConstructor* imp = V8TestEventConstructor::toNative(info.Holder());
    return v8String(imp->attr1(), info.GetIsolate(), ReturnUnsafeHandle);
}

static v8::Handle<v8::Value> attr1AttrGetterCallback(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return TestEventConstructorV8Internal::attr1AttrGetter(name, info);
}

static v8::Handle<v8::Value> attr2AttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    TestEventConstructor* imp = V8TestEventConstructor::toNative(info.Holder());
    return v8String(imp->attr2(), info.GetIsolate(), ReturnUnsafeHandle);
}

static v8::Handle<v8::Value> attr2AttrGetterCallback(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    return TestEventConstructorV8Internal::attr2AttrGetter(name, info);
}

static v8::Handle<v8::Value> constructor(const v8::Arguments& args)
{
    if (args.Length() < 1)
        return throwNotEnoughArgumentsError(args.GetIsolate());

    V8TRYCATCH_FOR_V8STRINGRESOURCE(V8StringResource<>, type, args[0]);
    TestEventConstructorInit eventInit;
    if (args.Length() >= 2) {
        V8TRYCATCH(Dictionary, options, Dictionary(args[1], args.GetIsolate()));
        if (!fillTestEventConstructorInit(eventInit, options))
            return v8Undefined();
    }

    RefPtr<TestEventConstructor> event = TestEventConstructor::create(type, eventInit);

    v8::Handle<v8::Object> wrapper = args.Holder();
    V8DOMWrapper::associateObjectWithWrapper(event.release(), &V8TestEventConstructor::info, wrapper, args.GetIsolate(), WrapperConfiguration::Dependent);
    return wrapper;
}
} // namespace TestEventConstructorV8Internal

static const V8DOMConfiguration::BatchedAttribute V8TestEventConstructorAttrs[] = {
    // Attribute 'attr1' (Type: 'attribute' ExtAttr: '')
    {"attr1", TestEventConstructorV8Internal::attr1AttrGetterCallback, 0, 0, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'attr2' (Type: 'attribute' ExtAttr: 'InitializedByEventConstructor')
    {"attr2", TestEventConstructorV8Internal::attr2AttrGetterCallback, 0, 0, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

bool fillTestEventConstructorInit(TestEventConstructorInit& eventInit, const Dictionary& options)
{
    options.get("attr2", eventInit.attr2);
    return true;
}

v8::Handle<v8::Value> V8TestEventConstructor::constructorCallback(const v8::Arguments& args)
{
    if (!args.IsConstructCall())
        return throwTypeError("DOM object constructor cannot be called as a function.", args.GetIsolate());

    if (ConstructorMode::current() == ConstructorMode::WrapExistingObject)
        return args.Holder();

    return TestEventConstructorV8Internal::constructor(args);
}

static v8::Persistent<v8::FunctionTemplate> ConfigureV8TestEventConstructorTemplate(v8::Persistent<v8::FunctionTemplate> desc, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    desc->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::configureTemplate(desc, "TestEventConstructor", v8::Persistent<v8::FunctionTemplate>(), V8TestEventConstructor::internalFieldCount,
        V8TestEventConstructorAttrs, WTF_ARRAY_LENGTH(V8TestEventConstructorAttrs),
        0, 0, isolate, currentWorldType);
    UNUSED_PARAM(defaultSignature); // In some cases, it will not be used.
    desc->SetCallHandler(V8TestEventConstructor::constructorCallback);
    desc->SetLength(1);

    // Custom toString template
    desc->Set(v8::String::NewSymbol("toString"), V8PerIsolateData::current()->toStringTemplate());
    return desc;
}

v8::Persistent<v8::FunctionTemplate> V8TestEventConstructor::GetTemplate(v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    V8PerIsolateData::TemplateMap::iterator result = data->templateMap(currentWorldType).find(&info);
    if (result != data->templateMap(currentWorldType).end())
        return result->value;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ =
        ConfigureV8TestEventConstructorTemplate(data->rawTemplate(&info, currentWorldType), isolate, currentWorldType);
    data->templateMap(currentWorldType).add(&info, templ);
    return templ;
}

bool V8TestEventConstructor::HasInstance(v8::Handle<v8::Value> value, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&info, value, currentWorldType);
}

bool V8TestEventConstructor::HasInstanceInAnyWorld(v8::Handle<v8::Value> value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&info, value, MainWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&info, value, IsolatedWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&info, value, WorkerWorld);
}


v8::Handle<v8::Object> V8TestEventConstructor::createWrapper(PassRefPtr<TestEventConstructor> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl.get());
    ASSERT(DOMDataStore::getWrapper(impl.get(), isolate).IsEmpty());

#if ENABLE(BINDING_INTEGRITY)
    checkTypeOrDieTrying(impl.get());
#endif

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &info, impl.get(), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper(impl, &info, wrapper, isolate, hasDependentLifetime ? WrapperConfiguration::Dependent : WrapperConfiguration::Independent);
    return wrapper;
}
void V8TestEventConstructor::derefObject(void* object)
{
    static_cast<TestEventConstructor*>(object)->deref();
}

} // namespace WebCore
