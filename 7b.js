import React from 'react';
function App() {
  const fruits = ['Apple', 'Banana', 'Mango', 'Orange', 'Pineapple'];
  return (
    <div style={{ textAlign: 'center', marginTop: '50px' }}>
      <h1>Fruit List</h1>
      <ul style={{ listStylePosition: 'inside', padding: 0, textAlign: 'center' }}>
        {fruits.map((fruit, index) => (
          <li key={index} style={{ margin: '10px', fontSize: '20px' }}>
            {fruit}
          </li>
        ))}
      </ul>
    </div>
  );
}
export default App;

