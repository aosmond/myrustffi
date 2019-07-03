#include <stdint.h>
#include <stdio.h>

struct LayoutGeometry {
  float top;
  float left;
  float width;
  float height;
};

struct SideOffsets {
  int32_t top;
  int32_t right;
  int32_t bottom;
  int32_t left;
};

struct WrState {
  uint64_t pipeline_id;
};

struct WrSpaceAndClipChain {
  uint64_t clip_chain;
};

enum class RepeatMode : uint8_t {
  Stretch,
  Repeat,
  Round,
  Space,

  Sentinel /* this must be last for serialization purposes. */
};

extern "C" void wr_dp_push_border_image(WrState *aState,
                             LayoutGeometry aRect,
                             LayoutGeometry aClip,
                             bool aIsBackfaceVisible,
                             const WrSpaceAndClipChain *aParent,
                             LayoutGeometry aWidths,
                             uint64_t aImage,
                             int32_t aWidth,
                             int32_t aHeight,
                             bool aFill,
                             SideOffsets aSlice,
                             LayoutGeometry aOutset,
                             RepeatMode aRepeatHorizontal,
                             RepeatMode aRepeatVertical);

int main() {
  WrState state { 1 };
  LayoutGeometry rect { 2.0, 2.1, 2.2, 2.3 };
  LayoutGeometry clip { 3.0, 3.1, 3.2, 3.3 };
  bool backfaceVisible = false;
  WrSpaceAndClipChain parent { 4 };
  LayoutGeometry widths { 5.0, 5.1, 5.2, 5.3 };
  uint64_t image = 6;
  int32_t width = 7;
  int32_t height = 8;
  bool fill = false;
  SideOffsets slice { 9, 10, 11, 12 };
  LayoutGeometry outset { 13.0, 13.1, 13.2, 13.3 };
  RepeatMode repeatHorizontal = RepeatMode::Stretch; // 0
  RepeatMode repeatVertical = RepeatMode::Stretch; // 0

  printf("c++ expect width=%d height=%d\n", width, height);
  printf("c++ expect slice=%d %d %d %d\n", slice.top, slice.right, slice.bottom, slice.left);
  printf("c++ expect outset=%f %f %f %f\n", outset.top, outset.left, outset.width, outset.height);
  printf("c++ expect repeat h=%d v=%d\n", (int)repeatHorizontal, (int)repeatVertical);

  wr_dp_push_border_image(&state, rect, clip, backfaceVisible, &parent, widths, image, width, height, fill, slice, outset, repeatHorizontal, repeatVertical);
  return 0;
}

