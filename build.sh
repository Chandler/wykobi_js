build_dir="${WYKOBI_JS_BUILD_DIR:-dist}"

source $EMSDK_DIR/emsdk_env.sh

mkdir -p $build_dir

emcc bindings/cpp/bindings.cpp \
    -I $WYKOBI_DIR \
    -o $build_dir/wykobi_wasm_loader.js  \
    -L/usr/lib -lstdc++ -lm -O3 \
    -s WASM=1 \
    -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' \
    -s MODULARIZE=1 -s 'EXPORT_NAME="WykobiJS"'