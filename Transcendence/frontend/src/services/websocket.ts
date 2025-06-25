let socket: WebSocket;
let onMessageCallback: ((data: any) => void) | null = null;

/**
 * Ouvre une nouvelle connexion WebSocket (pour CreateGame/JoinGame)
 * et retourne le WebSocket pour pouvoir y greffer des listeners.
 */
export function connectSocket(url: string): WebSocket {
  socket = new WebSocket(url);
  socket.addEventListener('open', () => {
    // Connection established
  });
  socket.addEventListener('message', (evt: MessageEvent) => {
    const data = JSON.parse(evt.data);
    onMessageCallback?.(data);
  });
  socket.addEventListener('close', () => {
    // Connection closed
  });
  socket.addEventListener('error', () => {
    // Connection error
  });
  return socket;
}

/**
 * Si une socket est déjà ouverte, on la réutilise ;
 * sinon on en crée une nouvelle.
 */
export function getSocket(url: string): WebSocket {
  if (socket && socket.readyState === WebSocket.OPEN) {
    return socket;
  }
  return connectSocket(url);
}

/**
 * Définit le callback invoqué à chaque message reçu.
 */
export function setOnMessage(cb: (data: any) => void) {
  onMessageCallback = cb;
}

export function closeSocket() {
  if (socket && socket.readyState === WebSocket.OPEN) {
    socket.close();
  }
  socket = undefined as any;
  onMessageCallback = null;
}

/**
 * Envoie un message JSON vers le serveur.
 */
export function sendMessage(type: string, payload: any) {
  if (socket && socket.readyState === WebSocket.OPEN) {
    socket.send(JSON.stringify({ type, payload }));
  }
}
