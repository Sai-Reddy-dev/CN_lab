import React from "react";
import ChildComponent from "./Childcomponent.js";

function App() {
  const student = {
    name: "sai",
    rollNumber: "23A91A05D3",
    course: "ReactJS"
  };

  return (
    <div style={{ textAlign: "center" }}>
      <h1>Sharing Data Between Components</h1>
      {/* Passing data to child component using props */}
      <ChildComponent studentData={student} />
    </div>
  );
}
export default App;


import React from "react";
function ChildComponent(props) {
  return (
    <div>
      <h2>Student Details:</h2>
      <p><b>Name:</b> {props.studentData.name}</p>
      <p><b>Roll Number:</b> {props.studentData.rollNumber}</p>
      <p><b>Course:</b> {props.studentData.course}</p>
    </div>
  );
}
export default ChildComponent;
