extern crate cc;


fn main() {
    cc::Build::new()
        .cpp(true)
        .include("cpp")
        .file("cpp/Engine.cpp")
        .file("cpp/bindings.cpp")
        .cpp_link_stdlib("stdc++")
        .warnings_into_errors(true)
        .compile("gui");
}