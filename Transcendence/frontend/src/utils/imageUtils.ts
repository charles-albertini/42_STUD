// Utilitaires pour la gestion des images

/**
 * Redimensionne et convertit un fichier image en base64
 */
export function resizeImageToBase64(file: File, maxWidth: number = 150, maxHeight: number = 150, quality: number = 0.8): Promise<string> {
  return new Promise((resolve, reject) => {
    const canvas = document.createElement('canvas');
    const ctx = canvas.getContext('2d');
    const img = new Image();
    
    img.onload = () => {
      // Calculer les nouvelles dimensions en gardant le ratio
      let { width, height } = img;
      
      if (width > height) {
        if (width > maxWidth) {
          height = (height * maxWidth) / width;
          width = maxWidth;
        }
      } else {
        if (height > maxHeight) {
          width = (width * maxHeight) / height;
          height = maxHeight;
        }
      }
      
      canvas.width = width;
      canvas.height = height;
      
      // Dessiner l'image redimensionnée
      ctx?.drawImage(img, 0, 0, width, height);
      
      // Convertir en base64
      const base64 = canvas.toDataURL('image/jpeg', quality);
      resolve(base64);
    };
    
    img.onerror = reject;
    img.src = URL.createObjectURL(file);
  });
}

/**
 * Valide si une chaîne est un base64 valide d'image
 */
export function isValidImageBase64(base64: string): boolean {
  const base64Regex = /^data:image\/(png|jpeg|jpg|gif|webp);base64,/;
  return base64Regex.test(base64);
}

/**
 * Obtient la taille approximative d'une image base64 en bytes
 */
export function getBase64Size(base64: string): number {
  const base64Data = base64.split(',')[1] || base64;
  return Math.round(base64Data.length * 0.75);
}

/**
 * Avatars par défaut en base64 (petites images optimisées)
 */
export const DEFAULT_AVATARS_BASE64 = {
  default: 'data:image/svg+xml;base64,PHN2ZyB3aWR0aD0iMTUwIiBoZWlnaHQ9IjE1MCIgdmlld0JveD0iMCAwIDE1MCAxNTAiIGZpbGw9Im5vbmUiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyI+CjxyZWN0IHdpZHRoPSIxNTAiIGhlaWdodD0iMTUwIiByeD0iNzUiIGZpbGw9IiNkNGFmMzciLz4KPHN2ZyB4PSI0NSIgeT0iNDUiIHdpZHRoPSI2MCIgaGVpZ2h0PSI2MCIgdmlld0JveD0iMCAwIDI0IDI0IiBmaWxsPSIjMDAwMDAwIj4KICA8cGF0aCBkPSJNMTIgMTJjMi4yMSAwIDQtMS43OSA0LTRzLTEuNzktNC00LTQtNCAxLjc5LTQgNCAxLjc5IDQgNCA0em0wIDJjLTIuNjcgMC04IDEuMzQtOCA0djJoMTZ2LTJjMC0yLjY2LTUuMzMtNC04LTR6Ii8+Cjwvc3ZnPgo8L3N2Zz4=',
}