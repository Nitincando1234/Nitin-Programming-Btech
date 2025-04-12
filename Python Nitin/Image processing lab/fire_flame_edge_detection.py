import cv2, numpy

cap = cv2.VideoCapture("./fire.mp4")

while True:
    ret, frame = cap.read()
    if not ret: break
    frame = cv2.resize(frame, (600, 600))
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    lower_range = numpy.array([0, 150, 150])
    higher_range = numpy.array([50, 255, 255])
    mask = cv2.inRange(hsv, lower_range, higher_range)
    blurred_mask = cv2.GaussianBlur(mask, (5, 5), 0)
    edges = cv2.Canny(blurred_mask, 50, 150)
    cv2.imshow("Original", frame)
    cv2.imshow("Mask", blurred_mask)
    cv2.imshow("Edges", edges)
    if cv2.waitKey(10) & 0xFF == ord("q"): break

cap.release()
cv2.destroyAllWindows()