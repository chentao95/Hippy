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

namespace hippy {
inline namespace render {
inline namespace native {

enum class RefreshStatus {
  Inactive,
  Drag,
  OverDrag,
  Refresh
};

class RefreshNodeDelegate {
public:
  virtual ~RefreshNodeDelegate() = default;
  virtual void OnHeadRefreshFinish() {}
  virtual void OnStartRefresh() {}
  virtual void OnEndRefresh() {}
  virtual void OnStateChange() {}
  virtual void OnStateChange(RefreshStatus refreshStatus) {}
  virtual void OnRefreshing() {}
};
class RefreshNode : public ArkUINode {
protected:
  RefreshNodeDelegate *RefreshNodeDelegate_;
public:
  RefreshNode();
  ~RefreshNode();

  void AddChild(ArkUINode &child);
  void InsertChild(ArkUINode &child, int32_t index);
  void RemoveChild(ArkUINode &child);
  void SetNodeDelegate(RefreshNodeDelegate *RefreshNodeDelegate);
};

} // namespace native
} // namespace render
} // namespace hippy
