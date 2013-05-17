/*
 * Copyright (C) 1999 Lars Knoll (knoll@kde.org)
 *           (C) 1999 Antti Koivisto (koivisto@kde.org)
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "config.h"
#include "core/html/HTMLUListElement.h"

#include "CSSPropertyNames.h"
#include "HTMLNames.h"
#include "core/dom/Attribute.h"

namespace WebCore {

using namespace HTMLNames;

HTMLUListElement::HTMLUListElement(const QualifiedName& tagName, Document* document)
    : HTMLElement(tagName, document)
{
    ASSERT(hasTagName(ulTag));
    ScriptWrappable::init(this);
}

PassRefPtr<HTMLUListElement> HTMLUListElement::create(Document* document)
{
    return adoptRef(new HTMLUListElement(ulTag, document));
}

PassRefPtr<HTMLUListElement> HTMLUListElement::create(const QualifiedName& tagName, Document* document)
{
    return adoptRef(new HTMLUListElement(tagName, document));
}

bool HTMLUListElement::isPresentationAttribute(const QualifiedName& name) const
{
    if (name == typeAttr)
        return true;
    return HTMLElement::isPresentationAttribute(name);
}

void HTMLUListElement::collectStyleForPresentationAttribute(const QualifiedName& name, const AtomicString& value, MutableStylePropertySet* style)
{
    if (name == typeAttr)
        addPropertyToPresentationAttributeStyle(style, CSSPropertyListStyleType, value);
    else
        HTMLElement::collectStyleForPresentationAttribute(name, value, style);
}

}
