#[repr(C)]
#[derive(Debug)]
pub struct LayoutGeometry {
    top: f32,
    left: f32,
    width: f32,
    height: f32,
}

#[repr(C)]
#[derive(Debug)]
pub struct SideOffsets {
    top: i32,
    right: i32,
    bottom: i32,
    left: i32,
}

#[repr(C)]
#[derive(Debug)]
pub struct WrState {
    pipeline_id: u64,
}

#[repr(C)]
#[derive(Debug)]
pub struct WrSpaceAndClipChain {
    clip_chain: u64,
}

#[repr(u8)]
#[derive(Debug, Copy, Clone, PartialEq, Eq, Hash)]
pub enum RepeatMode {
    Stretch,
    Repeat,
    Round,
    Space,
}

#[no_mangle]
pub extern "C" fn wr_dp_push_border_image(state: &mut WrState,
                                          rect: LayoutGeometry,
                                          clip: LayoutGeometry,
                                          is_backface_visible: bool,
                                          parent: &WrSpaceAndClipChain,
                                          widths: LayoutGeometry,
                                          image: u64,
                                          width: i32,
                                          height: i32,
                                          fill: bool,
                                          slice: SideOffsets,
                                          outset: LayoutGeometry,
                                          repeat_horizontal: RepeatMode,
                                          repeat_vertical: RepeatMode) {
    println!("got rust image {} width {} height {}", image, width, height);
    println!("got rust slice {:?}", slice);
    println!("got rust outset {:?}", outset);
    println!("got rust repeat h={} v={}", repeat_horizontal as u8, repeat_vertical as u8);
}
