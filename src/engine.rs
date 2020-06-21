use std::ffi::c_void;
use std::os::raw::c_char;
use crate::bindings::{engine_factory, register_button, AbstractButtonBinding, click};
use crate::Button;

pub struct Engine {
    ptr: *mut c_void
}

impl Engine {
    pub fn new() -> Engine {
        unsafe {
            Engine {
                ptr: engine_factory()
            }
        }
    }

    pub fn register_button<T>(&mut self, button: Box<T>)
        where T: Button {
        unsafe extern "C" fn click<T>(context: *mut T)
            where T: Button {
            let button_ref: &mut T = &mut *context;
            button_ref.click();
        }

        unsafe extern "C" fn inner_text<T>(context: *mut T) -> *const c_char
            where T: Button {
            let button_ref: &mut T = &mut *context;
            let text: String = button_ref.inner_text();
            let c_string = text.as_ptr() as *const c_char;
            std::mem::forget(text);
            c_string
        }

        let context: *mut T = Box::into_raw(button);

        let binding: Box<AbstractButtonBinding<T>> = Box::new(AbstractButtonBinding {
            click,
            inner_text,
            context,
        });

        let binding_ptr: *mut c_void = Box::into_raw(binding) as *mut c_void;

        unsafe { register_button(self.ptr as *mut c_void, binding_ptr); }
    }

    pub fn click(&self) {
        unsafe {
            click(self.ptr);
        }
    }
}

impl Drop for Engine {
    fn drop(&mut self) {
        unsafe { libc::free(self.ptr); }
    }
}