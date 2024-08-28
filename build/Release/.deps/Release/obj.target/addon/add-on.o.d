cmd_Release/obj.target/addon/add-on.o := c++ -o Release/obj.target/addon/add-on.o ../add-on.cpp '-DNODE_GYP_MODULE_NAME=addon' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DBUILDING_NODE_EXTENSION' -I/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node -I/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/src -I/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/deps/openssl/config -I/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/deps/openssl/openssl/include -I/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/deps/uv/include -I/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/deps/zlib -I/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/deps/v8/include -I../node_modules/nan  -O3 -gdwarf-2 -fno-strict-aliasing -mmacosx-version-min=11.0 -arch arm64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++17 -stdlib=libc++ -fno-rtti -fno-exceptions -MMD -MF ./Release/.deps/Release/obj.target/addon/add-on.o.d.raw   -c
Release/obj.target/addon/add-on.o: ../add-on.cpp \
  ../node_modules/nan/nan.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_version.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/errno.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/version.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/unix.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/threadpool.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/darwin.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/cppgc/common.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8config.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-array-buffer.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-local-handle.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-handle-base.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-internal.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-object.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-maybe.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-persistent-handle.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-weak-callback-info.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-primitive.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-data.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-value.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-traced-handle.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-container.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-context.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-snapshot.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-isolate.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-callbacks.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-promise.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-debug.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-script.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-memory-span.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-message.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-embedder-heap.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-function-callback.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-microtask.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-statistics.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-unwinder.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-embedder-state-scope.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-date.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-exception.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-extension.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-external.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-function.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-template.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-initialization.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-platform.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-source-location.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-json.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-locker.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-microtask-queue.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-primitive-object.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-proxy.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-regexp.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-typed-array.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-value-serializer.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-version.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-wasm.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_api.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/js_native_api.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/js_native_api_types.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_api_types.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_buffer.h \
  /Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_object_wrap.h \
  ../node_modules/nan/nan_callbacks.h \
  ../node_modules/nan/nan_callbacks_12_inl.h \
  ../node_modules/nan/nan_maybe_43_inl.h \
  ../node_modules/nan/nan_converters.h \
  ../node_modules/nan/nan_converters_43_inl.h \
  ../node_modules/nan/nan_new.h \
  ../node_modules/nan/nan_implementation_12_inl.h \
  ../node_modules/nan/nan_persistent_12_inl.h \
  ../node_modules/nan/nan_weak.h ../node_modules/nan/nan_object_wrap.h \
  ../node_modules/nan/nan_private.h \
  ../node_modules/nan/nan_typedarray_contents.h \
  ../node_modules/nan/nan_json.h ../node_modules/nan/nan_scriptorigin.h \
  ../Training.h
../add-on.cpp:
../node_modules/nan/nan.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_version.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/errno.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/version.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/unix.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/threadpool.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/uv/darwin.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/cppgc/common.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8config.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-array-buffer.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-local-handle.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-handle-base.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-internal.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-object.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-maybe.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-persistent-handle.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-weak-callback-info.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-primitive.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-data.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-value.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-traced-handle.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-container.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-context.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-snapshot.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-isolate.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-callbacks.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-promise.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-debug.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-script.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-memory-span.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-message.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-embedder-heap.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-function-callback.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-microtask.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-statistics.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-unwinder.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-embedder-state-scope.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-date.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-exception.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-extension.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-external.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-function.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-template.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-initialization.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-platform.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-source-location.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-json.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-locker.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-microtask-queue.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-primitive-object.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-proxy.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-regexp.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-typed-array.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-value-serializer.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-version.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/v8-wasm.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_api.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/js_native_api.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/js_native_api_types.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_api_types.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_buffer.h:
/Users/ellakerrigan/Library/Caches/node-gyp/22.7.0/include/node/node_object_wrap.h:
../node_modules/nan/nan_callbacks.h:
../node_modules/nan/nan_callbacks_12_inl.h:
../node_modules/nan/nan_maybe_43_inl.h:
../node_modules/nan/nan_converters.h:
../node_modules/nan/nan_converters_43_inl.h:
../node_modules/nan/nan_new.h:
../node_modules/nan/nan_implementation_12_inl.h:
../node_modules/nan/nan_persistent_12_inl.h:
../node_modules/nan/nan_weak.h:
../node_modules/nan/nan_object_wrap.h:
../node_modules/nan/nan_private.h:
../node_modules/nan/nan_typedarray_contents.h:
../node_modules/nan/nan_json.h:
../node_modules/nan/nan_scriptorigin.h:
../Training.h:
