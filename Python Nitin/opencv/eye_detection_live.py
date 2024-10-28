import cv2
import cv2.data
import numpy as np
cap=cv2.VideoCapture(0)
face_classifier=cv2.CascadeClassifier(cv2.data.haarcascades+"haarcascade_frontalface_default.xml")
eye_classifier=cv2.CascadeClassifier(cv2.data.haarcascades+"haarcascade_eye.xml")
while True:
    ret,frame=cap.read()
    gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
    faces=face_classifier.detectMultiScale(gray,1.3,5)
    for (x,y,w,h) in faces:
        cv2.rectangle(frame,(x,y),(x+w,y+h),(255,0,0),4)
        gray_faces=gray[y:y+h,x:x+w]
        gray_color=frame[y:y+h,x:x+w]
        eyes=eye_classifier.detectMultiScale(gray_faces,1.3,5)
        for (ex,ey,ew,eh) in eyes:
            cv2.rectangle(gray_color,(ex,ey),(ex+ew,ey+eh),(0,255,0),4)
    cv2.imshow("frame",frame)
    if cv2.waitKey(1)==ord('q'):
        break
cap.release()
cv2.destroyAllWindows()