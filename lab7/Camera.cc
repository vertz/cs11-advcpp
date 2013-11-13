#include "Camera.hh"

Camera::Camera(const Vector3F &pos, const Vector3F &look_at, const Vector3F &up, float fov /*= 60*/)
    : _pos(pos), _fov(fov)
{
    //The camera's direction vector simply becomes the 
    //difference between the look-at position and the camera's position, normalized
    
    _dir = look_at - _pos;
    _dir.normalize();
    
    //cameraRight = direction × up (using right-hand rule)
    
    _cameraRight = cross(_dir, up);
    _cameraRight.normalize();
    
    //cameraUp = cameraRight × direction (using right-hand rule)
    
    _cameraUp = cross(_cameraRight, _dir);
    _cameraUp.normalize();
    
    //dist = 0.5 / tan(fov / 2)
    
    _dist = 0.5 / tanf((_fov * float(M_PI) / 180) / 2);
    
    _valid = true;
}

Ray Camera::getRayForPixel(int x, int y, int imgSize) const
{
    assert(_valid);
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

//# (px, py, pz) (lx, ly, lz) (ux, uy, uz)
Camera read_Camera(std::istream &is)
{
    Camera cam; 
    if (!is) return cam;

    Vector3F p_v;
    Vector3F l_v;
    Vector3F u_v;

    is >> p_v;
    is >> l_v;
    is >> u_v;

    if (is){
        cam = Camera(p_v, l_v, u_v);
    }
    
    return cam;
}















