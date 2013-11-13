#include "Camera.hh"

Camera::Camera(const Vector3F &pos, const Vector3F &look_at, const Vector3F &up, float fov /*= 60*/)
    : _pos(pos), _fov(fov)
{
    //The camera's direction vector simply becomes the 
    //difference between the look-at position and the camera's position, normalized
    
    _dir = look_at - _pos;
    _dir.normalize();
    
    //cameraRight = direction × up (using right-hand rule)
    
    _cameraRight = _dir % up;
    _cameraRight.normalize();
    
    //cameraUp = cameraRight × direction (using right-hand rule)
    
    _cameraUp = _cameraRight % _dir;
    _cameraUp.normalize();
    
    //dist = 0.5 / tan(fov / 2)
    
    _dist = 0.5 / tanf((_fov * float(M_PI) / 180) / 2);
}

Ray Camera::getRayForPixel(int x, int y, int imgSize) const
{
    assert(x >= 0 && x < imgSize);
    assert(y >= 0 && y < imgSize);

    // dist = distance between camera location and the grid of pixels, as
    // computed earlier.  direction = normalized camera direction vector.
    
    Vector3F pixelDir = ((_dist * _dir) +
                        ((0.5 - (float) y / (float) (imgSize - 1)) * _cameraUp) +
                        (((float) x / (float) (imgSize - 1) - 0.5) * _cameraRight));

    Ray pixelRay(_pos, pixelDir);
    return pixelRay;
}

















