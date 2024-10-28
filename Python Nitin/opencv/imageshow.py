import cv2
import random
img=cv2.imread("C:/Nitin Programming Btech/Python Nitin/opencv/example.png",-1)
img=cv2.resize(img,(0,0),fx=0.75,fy=0.75)
img2=img.copy()
for i in range(100):
    for j in range(100):
        img2[i][j]=[random.randint(0,1),random.randint(0,1),random.randint(0,1),255]
cv2.imshow('frame',img)
cv2.imshow('frame1',img2)
cv2.imshow('rotated',cv2.rotate(img,cv2.ROTATE_90_CLOCKWISE))
cv2.imwrite("C:/Nitin Programming Btech/Python Nitin/opencv/example_written.png",img)
print(img)
cv2.waitKey(0)
cv2.destroyAllWindows()