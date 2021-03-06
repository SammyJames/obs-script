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

#include <obs-module.h>

#include "ScriptModule.h"

OBS_DECLARE_MODULE()
OBS_MODULE_AUTHOR("Samantha James")

bool obs_module_load(void)
{
    return Script::Module::Get().OnLoad();
}

void obs_module_unload(void)
{
    Script::Module::Get().OnUnload();
}

void obs_module_post_load(void)
{
    Script::Module::Get().OnPostLoad();
}

const char* obs_module_name(void)
{
    return "Script Plugin";
}

const char* obs_module_description(void)
{
    return "a plugin for OBS that allows for scripting";
}