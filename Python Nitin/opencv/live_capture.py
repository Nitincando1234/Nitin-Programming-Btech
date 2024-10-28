import numpy as np
import cv2
cap=cv2.VideoCapture(0)
while True:
    ret,frame=cap.read()
    #to get height and width of the capture frame\
    height=int(cap.get(4))
    width=int(cap.get(3))
    frame=cv2.resize(frame,(512,512))
    #split in two parts
    image=np.zeros((frame.shape),np.uint8)
    smaller_frames=cv2.resize(frame,(0,0),fx=.5,fy=1)
    image[:512,:512//2]=cv2.rotate(smaller_frames,cv2.ROTATE_180)
    image[:512,512//2:]=smaller_frames
    cv2.imshow('frame',frame)
    cv2.imshow('splitted_frames',image)
    if cv2.waitKey(1)==ord('q'):
        break
cap.release()
cv2.destroyAllWindows()