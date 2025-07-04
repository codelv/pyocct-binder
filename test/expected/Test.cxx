/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019-2020  Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Test_Enum.h>
#include <Test_Class.h>
#include <Test_Getter.h>
#include <Test_KeepAlive.h>
#include <Test_Pname.h>

// Testing +before_module line 1
// Testing +before_module line 2

PYBIND11_MODULE(Test, mod) {


// ENUM: TAGGEDENUM
py::enum_<TaggedEnum>(mod, "TaggedEnum", "")
	.value("TaggedEnum_A", TaggedEnum::TaggedEnum_A)
	.value("TaggedEnum_B", TaggedEnum::TaggedEnum_B)
	.export_values();

mod.attr("UnTaggedEnum_A") = py::cast(int(UnTaggedEnum_A));
mod.attr("UnTaggedEnum_B") = py::cast(int(UnTaggedEnum_B));


// CLASS: TEST_SIMPLECLASS
// Before type
// Testing +before_type line 1
// Testing +before_type line 2

py::class_<Test_SimpleClass> cls_Test_SimpleClass(mod, "Test_SimpleClass", "Test class");

// Constructors
cls_Test_SimpleClass.def(py::init<>());

// Methods
cls_Test_SimpleClass.def("TestReturnPolicy1", (int (Test_SimpleClass::*)()) &Test_SimpleClass::TestReturnPolicy1, "");
cls_Test_SimpleClass.def("TestReturnPolicy2", (const int & (Test_SimpleClass::*)()) &Test_SimpleClass::TestReturnPolicy2, "");
cls_Test_SimpleClass.def("TestReturnPolicy3", (int & (Test_SimpleClass::*)()) &Test_SimpleClass::TestReturnPolicy3, "", py::return_value_policy::reference_internal);

// After type
// Testing +after_type line 1
// Testing +after_type line 2

// TYPEDEF: TAGGEDENUM

// TYPEDEF: UNTAGGEDENUM

// CLASS: TEST_GETTER
py::class_<Test_Getter> cls_Test_Getter(mod, "Test_Getter", "");

// Constructors
cls_Test_Getter.def(py::init<>());

// Methods
cls_Test_Getter.def("OtherValue", (int & (Test_Getter::*)()) &Test_Getter::OtherValue, "");
cls_Test_Getter.def("Value", (int & (Test_Getter::*)()) &Test_Getter::Value, "", py::return_value_policy::reference_internal);
cls_Test_Getter.def("SetValue", (int (Test_Getter::*)(int)) &Test_Getter::SetValue, "", py::arg("v"));

// CLASS: TEST_NODE
py::class_<Test_Node> cls_Test_Node(mod, "Test_Node", "");

// Constructors
cls_Test_Node.def(py::init<>());

// CLASS: TEST_MESH
py::class_<Test_Mesh> cls_Test_Mesh(mod, "Test_Mesh", "");

// Constructors
cls_Test_Mesh.def(py::init<>());

// Methods
cls_Test_Mesh.def("AddNode", (void (Test_Mesh::*)(const int, Test_Node*)) &Test_Mesh::AddNode, "", py::arg("id"), py::arg("node"), py::keep_alive<1, 2>());

// CLASS: TEST_PNAME
py::class_<Test_Pname> cls_Test_NewName(mod, "Test_NewName", "Test class");

// Constructors
cls_Test_NewName.def(py::init<>());


}
