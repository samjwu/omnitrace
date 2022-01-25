// Copyright (c) 2018 Advanced Micro Devices, Inc. All Rights Reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// with the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// * Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimers.
//
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimers in the
// documentation and/or other materials provided with the distribution.
//
// * Neither the names of Advanced Micro Devices, Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this Software without specific prior written permission.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS WITH
// THE SOFTWARE.

#pragma once

#include "library/common.hpp"
#include "library/components/backtrace.hpp"
#include "library/components/fwd.hpp"
#include "library/defines.hpp"
#include "library/thread_data.hpp"
#include "library/timemory.hpp"

#include <timemory/macros/language.hpp>
#include <timemory/sampling/sampler.hpp>
#include <timemory/variadic/types.hpp>

#include <cstdint>
#include <memory>
#include <set>

namespace omnitrace
{
namespace sampling
{
using component::backtrace;
using component::backtrace_cpu_clock;   // NOLINT
using component::backtrace_fraction;    // NOLINT
using component::backtrace_wall_clock;  // NOLINT
using component::sampling_cpu_clock;
using component::sampling_percent;
using component::sampling_wall_clock;

std::set<int>
setup();

std::set<int>
shutdown();

void block_signals(std::set<int> = {});

void unblock_signals(std::set<int> = {});

using bundle_t          = tim::lightweight_tuple<backtrace>;
using sampler_t         = tim::sampling::sampler<bundle_t, tim::sampling::dynamic>;
using sampler_instances = omnitrace_thread_data<sampler_t, api::sampling>;

std::unique_ptr<sampler_t>&
get_sampler(int64_t _tid = threading::get_id());

}  // namespace sampling
}  // namespace omnitrace
