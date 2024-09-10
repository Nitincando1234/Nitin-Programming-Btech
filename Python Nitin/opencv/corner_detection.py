import cv2
import numpy as np
img=cv2.imread('C:/Nitin Programming Btech/Python Nitin/opencv/image.png',-1)
frame=img.copy()
frame=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
corners=cv2.goodFeaturesToTrack(frame,250,0.60,25)
corners=np.int0(corners)
for corner in corners:
    x,y=corner.ravel()
    cv2.circle(img,(x,y),5,(255,0,0),-1)
cv2.imshow("Detected_corners",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
