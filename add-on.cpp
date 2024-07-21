
#include <nan.h>
#include "Training.h"

NAN_METHOD(AddEmployee) {
    if (info.Length() < 1) {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }
    if (!info[0]->IsString()) {
        Nan::ThrowTypeError("Wrong arguments");
        return;
    }
    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value str(isolate, info[0]->ToString(Nan::GetCurrentContext()).ToLocalChecked());
    std::string dbPath(*str);

    Training training(dbPath.c_str());
    training.addEmployee();
    info.GetReturnValue().Set(Nan::New("Employee added successfully").ToLocalChecked());
}

NAN_METHOD(DeleteEmployee) {
    if (info.Length() < 2) {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }
    if (!info[0]->IsString() || !info[1]->IsNumber()) {
        Nan::ThrowTypeError("Wrong arguments");
        return;
    }
    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value str(isolate, info[0]->ToString(Nan::GetCurrentContext()).ToLocalChecked());
    std::string dbPath(*str);

    int id = info[1]->NumberValue(Nan::GetCurrentContext()).FromJust();

    Training training(dbPath.c_str());
    training.deleteEmployee(id);
    info.GetReturnValue().Set(Nan::New("Employee deleted successfully").ToLocalChecked());
}

NAN_METHOD(RandomizeEmployee) {
    if (info.Length() < 1) {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }
    if (!info[0]->IsString()) {
        Nan::ThrowTypeError("Wrong arguments");
        return;
    }
    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value str(isolate, info[0]->ToString(Nan::GetCurrentContext()).ToLocalChecked());
    std::string dbPath(*str);

    Training training(dbPath.c_str());
    training.randomizeEmployee();
    info.GetReturnValue().Set(Nan::New("Employee randomized successfully").ToLocalChecked());
}

NAN_METHOD(PrintInProgressEmployees) {
    if (info.Length() < 1) {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }
    if (!info[0]->IsString()) {
        Nan::ThrowTypeError("Wrong arguments");
        return;
    }
    v8::Isolate* isolate = info.GetIsolate();
    v8::String::Utf8Value str(isolate, info[0]->ToString(Nan::GetCurrentContext()).ToLocalChecked());
    std::string dbPath(*str);

    Training training(dbPath.c_str());
    training.printInProgressEmployees();
    info.GetReturnValue().Set(Nan::New("In progress employees printed").ToLocalChecked());
}

NAN_MODULE_INIT(Init) {
    Nan::Set(target, Nan::New("addEmployee").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(AddEmployee)).ToLocalChecked());
    Nan::Set(target, Nan::New("deleteEmployee").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(DeleteEmployee)).ToLocalChecked());
    Nan::Set(target, Nan::New("randomizeEmployee").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(RandomizeEmployee)).ToLocalChecked());
    Nan::Set(target, Nan::New("printInProgressEmployees").ToLocalChecked(),
        Nan::GetFunction(Nan::New<v8::FunctionTemplate>(PrintInProgressEmployees)).ToLocalChecked());
}

NODE_MODULE(training, Init)
