use std::ffi::c_void;
use crate::Button;
use std::os::raw::c_char;


#[repr(C)]
pub struct AbstractButtonBinding<T>
where T: Button{
    pub click: unsafe extern fn(*mut T),
    pub inner_text: unsafe extern fn(*mut T) -> *const c_char,
    pub context: *mut T,
}

#[link(name = "gui")]
extern "C" {
    // Return a void pointer from the heap, the alternative would have been to write recursively
    // all the fields in a #[repr(C)] struct Engine ...
    pub fn engine_factory() -> *mut c_void;
    pub fn register_button(engine: *mut c_void, button: *mut c_void);
    pub fn click(engine: *mut c_void);
}