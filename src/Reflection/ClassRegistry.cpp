// Copyright � Samantha James

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the �Software�), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED �AS IS�, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "types.h"

#include "ClassRegistry.h"

#include "Utils\ReadWriteMutex.h"

namespace
{
    static Script::Utils::ReadWriteMutex SRWMutex;
    static std::unordered_map<std::string, Script::Reflection::ClassWalker> ClassStorage;

    static const Script::Reflection::ClassWalker skEmptyClassOutline;
}

namespace Script
{
    namespace Reflection
    {

        /*static*/ const ClassWalker& ClassRegistry::Find(const char* const typeName)
        {
            Utils::ReadLock lock(SRWMutex);
            if (ClassStorage.find(typeName) != ClassStorage.end())
                return ClassStorage[ typeName ];

            assert(!"unable to find a class outline for this type");
            return skEmptyClassOutline;
        }

        /*static*/ void ClassRegistry::List(std::vector<std::string>& result)
        {
            Utils::ReadLock lock(SRWMutex);
            for (const auto& iter : ClassStorage)
                result.push_back(iter.first);
        }

        /*static*/ void ClassRegistry::Store(const char* const typeName, ClassWalker&& outline)
        {
            Utils::WriteLock lock(SRWMutex);
            ClassStorage[ typeName ] = std::move(outline);
        }
    }
}
