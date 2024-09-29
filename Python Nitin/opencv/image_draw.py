import cv2
import numpy as np
cap=cv2.VideoCapture(0)
while True:
    ret, frame=cap.read()
    height=int(cap.get(4))
    width=int(cap.get(3))
    img=frame.copy
    img=cv2.line(frame,(0,0),(width,height),(255,255,0),5)
    img=cv2.circle(frame,(width//2,height//2),30,(255,255,255),-1)
    font=cv2.FONT_HERSHEY_SIMPLEX
    img=cv2.putText(frame,"The Good Image! ",((width//2)-140,height//2+7),font,1,(0,0,0),2)
    cv2.imshow("Frame",frame)
    if(cv2.waitKey(1)==ord('q')):
        break
cap.release()
cv2.destroyAllWindows()