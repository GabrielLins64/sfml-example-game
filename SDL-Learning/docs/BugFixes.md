# Bug fixes

## Warnings / Errors:

- **"libpng warning: iCCP: known incorrect sRGB profile"**

**Solution:** Fix the PNG images in assets with mogrify:

> $ mogrify *.png
