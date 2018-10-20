#ifndef VEC2_H
# define VEC2_H

struct Vec2
{
	Vec2(void);
	Vec2(double x_, double y_);
	Vec2(Vec2 const& v);
	~Vec2(void);

	Vec2& operator=(Vec2 const& v);
	Vec2 operator+(Vec2 const& v);
	Vec2 operator-(Vec2 const& v);
	bool operator==(Vec2 const& v) const;

	double	x;
	double	y;
};

#endif
