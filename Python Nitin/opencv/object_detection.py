import cv2
import numpy as np
main_img=cv2.imread("C:/Nitin Programming Btech/Python Nitin/opencv/image copy.png",0)
template_img=cv2.imread("C:/Nitin Programming Btech/Python Nitin/opencv/Screenshot 2024-04-07 221523.png",0)
h,w=template_img.shape
methods=[cv2.TM_CCOEFF, cv2.TM_CCOEFF_NORMED, cv2.TM_CCORR,cv2.TM_CCORR_NORMED, cv2.TM_SQDIFF, cv2.TM_SQDIFF_NORMED]
for method in methods:
    main_img_bgr=cv2.imread("C:/Nitin Programming Btech/Python Nitin/opencv/image copy.png",-1)
    img2=main_img.copy()
    result=cv2.matchTemplate(main_img,template_img,method)
    min,max,min_loc,max_loc=cv2.minMaxLoc(result)
    if method==cv2.TM_SQDIFF or method==cv2.TM_SQDIFF_NORMED:
        location=min_loc
    else:
        location=max_loc
    bottom_left_location=(location[0]+w,location[1]+h)
    cv2.rectangle(main_img_bgr,location,bottom_left_location,(255,0,0),2)
    cv2.imshow("Frame",main_img_bgr)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
