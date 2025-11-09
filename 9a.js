import React, { useState } from "react";

function HooksExample() {
  // Declare a state variable called 'count' with initial value 0
  const [count, setCount] = useState(0);

  return (
    <div style={{ textAlign: "center" }}>
      <h1>Understanding the Importance of Hooks</h1>
      <h2>Current Count: {count}</h2>
      <button onClick={() => setCount(count + 1)}>Increment</button>
      <button onClick={() => setCount(count - 1)}>Decrement</button>
         </div>
  );
}

export default HooksExample;


import React from 'react';
import ReactDOM from 'react-dom/client'
import App from './App';
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<App />);
