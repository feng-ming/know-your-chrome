/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"

#include "core/html/canvas/OESElementIndexUint.h"
#include "core/platform/graphics/Extensions3D.h"

namespace WebCore {

OESElementIndexUint::OESElementIndexUint(WebGLRenderingContext* context)
    : WebGLExtension(context)
{
    context->graphicsContext3D()->getExtensions()->ensureEnabled("GL_OES_element_index_uint");
}

OESElementIndexUint::~OESElementIndexUint()
{
}

WebGLExtension::ExtensionName OESElementIndexUint::getName() const
{
    return OESElementIndexUintName;
}

PassOwnPtr<OESElementIndexUint> OESElementIndexUint::create(WebGLRenderingContext* context)
{
    return adoptPtr(new OESElementIndexUint(context));
}

bool OESElementIndexUint::supported(WebGLRenderingContext* context)
{
    Extensions3D* extensions = context->graphicsContext3D()->getExtensions();
    return extensions->supports("GL_OES_element_index_uint");
}

const char* OESElementIndexUint::getExtensionName()
{
    return "OES_element_index_uint";
}

} // namespace WebCore
