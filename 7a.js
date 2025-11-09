import React, { useState } from 'react';
function App() {
    
    const [isLoggedIn, setIsLoggedIn] = useState(false);
    const handleLogin = () => setIsLoggedIn(true);
    const handleLogout = () => setIsLoggedIn(false);
    return (
        <div style={{ textAlign: 'center', marginTop: '50px' }}>
          {isLoggedIn ? (
            <>
              <h1>Welcome Back, User!</h1>
              <button onClick={handleLogout}>Logout</button>
            </>
          ) : (
            <>
              <h1>your account</h1>
              <button onClick={handleLogin}>Login</button>
            </>
          )}
        </div>
      );
}
export default App;


import React from 'react';
import ReactDOM from 'react-dom/client'
import App from './App';
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<App />);
