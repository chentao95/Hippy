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

#pragma once

#include "renderer/arkui/arkui_node.h"
#include "renderer/arkui/arkui_node_registry.h"
#include "renderer/arkui/refresh_node.h"


namespace hippy {
inline namespace render {
inline namespace native {

class WaterFlowNodeDelegate {
public:
  virtual ~WaterFlowNodeDelegate() = default;
  virtual void OnScrollIndex(int32_t firstIndex, int32_t lastIndex) {}
  virtual void OnReachEnd() {}
  virtual void OnScroll(float xOffset, float yOffset) {}
  virtual void OnScrollStart() {}
  virtual void OnScrollStop() {}
  virtual void OnTouch(int32_t actionType) {}
  virtual void OnHeadRefreshFinish() {}
  virtual void OnStartRefresh() {}
  virtual void OnEndRefresh() {}
  virtual void OnStateChange(RefreshStatus refreshStatus) {}
  virtual void OnRefreshing() {}
  virtual void OnReachStart() {}
  virtual void OnAppear() {}
  virtual void OnDisAppear() {}
};
class WaterFlowNode : public ArkUINode {
protected:
  WaterFlowNodeDelegate *WaterFlowNodeDelegate_ = nullptr;
  int32_t itemIndex_ = -1;
public:
  WaterFlowNode();
  ~WaterFlowNode();

  void AddChild(ArkUINode &child);
  void InsertChild(ArkUINode &child, int32_t index);
  void RemoveChild(ArkUINode &child);
  void RemoveAllChildren();
  HRPoint GetScrollOffset();
  void SetScrollEdgeEffect(bool hasEffect);
  void ScrollTo(float offsetX, float offsetY, bool animated);
  void ScrollToIndex(int32_t index, bool animated, bool isScrollAlignStart);
  void SetColumnsTemplate(std::string columnsTemplate);
  void SetNodeDelegate(WaterFlowNodeDelegate *waterFlowNodeDelegate);
  void SetItemIndex(int32_t index) { itemIndex_ = index; }
  void SetPadding(float left, float top, float right, float bottom);
  void OnNodeEvent(ArkUI_NodeEvent *event) override;
  // void OnTouchEvent(ArkUI_UIInputEvent *event);
};

} // namespace native
} // namespace render
} // namespace hippy
