import cv2
import numpy as np
cap=cv2.VideoCapture(0)
ret,frame=cap.read()
cv2.namedWindow('Sketch Maker')
ltc=cv2.createTrackbar('LTC','Sketch Maker',0,255,lambda x:None)
utc=cv2.createTrackbar('UTC','Sketch Maker',0,255,lambda x:None)
roi=cv2.selectROI('Sketch Maker',frame,False,False)
print("Please Enter Any Key to Start: ")
cv2.waitKey(0)      
while True:
    ret,frame=cap.read()
    x,y,w,h=roi
    image=frame[y:y+h,x:x+w]
    image=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
    image=cv2.GaussianBlur(image,(15,15),0)
    ltc=cv2.getTrackbarPos('LTC','Sketch Maker')
    utc=cv2.getTrackbarPos('UTC','Sketch Maker')
    image=cv2.Canny(image,ltc,utc)
    ret,image=cv2.threshold(image,50,255,cv2.THRESH_BINARY_INV)
    image=cv2.cvtColor(image,cv2.COLOR_GRAY2BGR)
    frame[y:y+h,x:x+w]=image
    cv2.imshow('Sketch Maker',frame)
    if(cv2.waitKey(1)==ord('q')):
        break
cap.release()
cv2.destroyAllWindows()
