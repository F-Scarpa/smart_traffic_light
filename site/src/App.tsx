import { useState, useEffect} from 'react'

import './App.css'


function App() {
  
  //const [btnState, setBtnState] = useState(true);
  const [status, setStatus] = useState("pending...");


  const disable_traffic_light = async () =>     
  {                                                                         
    const webResult = await fetch("/api/disable");  
    console.log(webResult);
    setStatus("Disabled")
  }

    const auto_traffic_light = async () =>     
  {                                                                         
    const webResult = await fetch("/api/auto");  
    console.log(webResult);
    setStatus("Auto")
  }

    const error_traffic_light = async () =>     
  {                                                                         
    const webResult = await fetch("/api/error");  
    console.log(webResult);
    setStatus("Error")
  }

    const man_traffic_light = async () =>     
  {                                                                         
    const webResult = await fetch("/api/pedestrian-call");  
    console.log(webResult);
    setStatus("Manual")
  }

  const getText = async () =>     
  {                                                                         
    const webResult = await fetch("/api/text");  
    console.log(webResult);
    setStatus("auto")
  }

const getCurrentDate = () => {
  const now = new Date();
  const day = String(now.getDate()).padStart(2, "0");       // giorno con 2 cifre
  const month = String(now.getMonth() + 1).padStart(2, "0"); // mese (0-indexed!) quindi +1
  const year = now.getFullYear();

  return `${day}/${month}/${year}`;
};
  const [currentDate, setCurrentDate] = useState(getCurrentDate());

const getCurrentTime = () => {
  const now = new Date();
  const hours = String(now.getHours()).padStart(2, "0");   // ore 0-23
  const minutes = String(now.getMinutes()).padStart(2, "0"); // minuti 0-59
  return `${hours}:${minutes}`;
};
const [currentTime, setCurrentTime] = useState(getCurrentTime());


  useEffect(
    () => {
        getText();      
      },         
    []                
  );

  //update every minute
  useEffect(() => {
    const interval = setInterval(() => {
      setCurrentDate(getCurrentDate()); 
    }, (1000 * 60) *24); 
    return () => clearInterval(interval); 
  }, []);


  useEffect(() => {
  const interval = setInterval(() => {
    setCurrentTime(getCurrentTime());
  }, 1000 * 60); 
  return () => clearInterval(interval); 
}, []);


  


  return (
    <>

      <h1>{status}</h1>
      <h2>Oggi: {currentDate}</h2>
      <h2>Ora: {currentTime}</h2>
      <button onClick = {disable_traffic_light}>Disable</button>
      <button onClick = {auto_traffic_light}>Auto</button>
      <button onClick = {error_traffic_light}>Error</button>
      <button onClick = {man_traffic_light}>Manual</button>

  
    </>
  )
}

export default App
