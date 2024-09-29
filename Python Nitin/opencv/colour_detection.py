import cv2
import numpy as np
cap=cv2.VideoCapture(0)
while True:
    ret,frame=cap.read()
    hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    lowerblack=np.array([255, 255, 255])
    upperblack=np.array([255,255,255])
    mask=cv2.inRange(hsv,lowerblack,upperblack)
    result=cv2.bitwise_and(frame,frame,mask=mask)
    cv2.imshow("color_detected_frame",result)
    cv2.imshow("normal_frame",frame)
    if cv2.waitKey(1)==ord('q'):
        break
cap.release()
cv2.destroyAllWindows()