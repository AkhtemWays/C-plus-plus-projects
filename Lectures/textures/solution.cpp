#include "common.h"

using namespace std;

// Р­С‚РѕС‚ С„Р°Р№Р» СЃРґР°С‘С‚СЃСЏ РЅР° РїСЂРѕРІРµСЂРєСѓ
namespace FIGURES {
struct Border {
public:
  Border(const Point& pos,const Size& s) {
    top_left, top_right, bot_left, bot_right = pos;
    top_right.x = top_right.x + s.height;
    bot_left.y = bot_left.y - s.width;
    bot_right.y = bot_left.y;
    bot_right.x = bot_left.x + s.height;
  }
Point top_left, top_right, bot_right, bot_left;
};
class Rectange : public IShape {
    std::unique_ptr<IShape> Clone() const {
        return make_unique<IShape>(this);
    }
    void SetPosition(Point p) {
       point.x = p.x;
       point.y = p.y;
    }
    Point GetPosition() const {
        return point;
    }
    void SetSize(Size s) {
       SIZE_.width = s.width;
       SIZE_.height = s.height;
    }
    Size GetSize() const {
        return SIZE_;
    }
    void SetTexture(std::shared_ptr<ITexture> itext) {
         itexture = move(itext);
    }
    ITexture* GetTexture() const {
        return itexture.get();
    }
    void Draw(Image& img) const {
        
    }


private:
  Point point;
  Size SIZE_;
  shared_ptr<ITexture> itexture = nullptr;
  Border border;

};
class Ellipse : public IShape {
    std::unique_ptr<IShape> Clone() const {
        return make_unique<IShape>(this);
    }
    void SetPosition(Point p) {
       point.x = p.x;
       point.y = p.y;
    }
    Point GetPosition() const {
        return point;
    }
    void SetSize(Size s) {
       SIZE_.width = s.width;
       SIZE_.height = s.height;
    }
    Size GetSize() const {
        return SIZE_;
    }
    void SetTexture(std::shared_ptr<ITexture> itext) {
         itexture = move(itext);
    }
    ITexture* GetTexture() const {
        return itexture.get();
    }
    void Draw(Image& img) const {
        if (!img.empty()) {
            const Image texture_image = itexture ? itexture->GetImage() :
			Image(SIZE_.height, std::string(SIZE_.width, '.'));
            const int n = static_cast<int>(img.size());
		    const int m = static_cast<int>(img[0].size());
            for (int i = border.top_left.x; i < border.bot_left.x; ++i) {
                for (int j = border.top_left.y; j < border.top_right.y; ++j) {
                    if (i >= 0 && i < n && j >= 0 && j < m) {
                        const Point point_ = Point{ j - point.x, i - point.y };
					    const int i_index = i - point.y;
					    const int j_index = j - point.x;
                        if (CheckPointInShape(point_)) {
                            if (CheckPointInTexture(point_, texture_image))
                        {
							img[i][j] = texture_image[point_.y][point_.x];
                        }
                        else
                        {
							img[i][j] = '.';
                        }
                        }
                    }
                }
            }
        }
    }
private:
  Point point;
  Size SIZE_;
  shared_ptr<ITexture> itexture = nullptr;
  Border border;
};
}
// РќР°РїРёС€РёС‚Рµ СЂРµР°Р»РёР·Р°С†РёСЋ С„СѓРЅРєС†РёРё
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
    if (shape_type == ShapeType::Rectangle) {
         unique_ptr<FIGURES::Rectange> rectangle = make_unique<FIGURES::Rectange>();
         return move(rectangle);
    } else if (shape_type == ShapeType::Ellipse) {
        unique_ptr<FIGURES::Ellipse> ellipse = make_unique<FIGURES::Ellipse>();
        return move(ellipse);
    }
}