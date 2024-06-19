/*
 *
 * Tencent is pleased to support the open source community by making
 * Hippy available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "renderer/components/waterfall_item_view.h"
#include "renderer/utils/hr_value_utils.h"

namespace hippy {
inline namespace render {
inline namespace native {

WaterfallItemView::WaterfallItemView(std::shared_ptr<NativeRenderContext> &ctx) : BaseView(ctx) {}

WaterfallItemView::~WaterfallItemView() {}

StackNode &WaterfallItemView::GetLocalRootArkUINode() { return stackNode_; }

bool WaterfallItemView::SetProp(const std::string &propKey, const HippyValue &propValue) {
  if (propKey == "type") {
    if (propValue.IsString()) {
      propValue.ToString(type_);
    } else if (propValue.IsNumber()) {
      int32_t value = HRValueUtils::GetInt32(propValue);
      type_ = std::to_string(value);
    } else {
      type_ = "NoType" + std::to_string(tag_);
    }
    return true;
  }
  return BaseView::SetProp(propKey, propValue);
}

void WaterfallItemView::OnChildInserted(std::shared_ptr<BaseView> const &childView, int32_t index) {
  BaseView::OnChildInserted(childView, index);
  stackNode_.InsertChild(childView->GetLocalRootArkUINode(), index);
}

void WaterfallItemView::OnChildRemoved(std::shared_ptr<BaseView> const &childView) {
  BaseView::OnChildRemoved(childView);
  stackNode_.RemoveChild(childView->GetLocalRootArkUINode());
}

void WaterfallItemView::updateRenderViewFrame(const HRRect &frame, const HRPadding &padding) {
  stackNode_.SetPosition(HRPosition(0, 0));
  stackNode_.SetSize(HRSize(frame.width, frame.height));
  width_ = frame.width;
  height_ = frame.height;
}
} // namespace native
} // namespace render
} // namespace hippy
