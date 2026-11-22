#include "f3_common.h"
// src/staging/blk_00d20000_od_o2_nood_variant.cpp - flag-variant unit created 2026-10-24 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/staging/blk_00d20000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00d20000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    float _mm_cvtss_f32(__m128);
    void _mm_store_ss(float*, __m128);
}

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline float lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        __m128 z = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), y);
        float r;
        _mm_store_ss(&r, z);
        return r;
    }
};

struct ContactBody
{
    char unk00[0xa];
    unsigned char m_qualityA;
    unsigned char unk0b;
    unsigned char m_qualityC;
    char unk0d[0xb0 - 0xd];
    float m_uiCommandId;
    char unkb4[0xd0 - 0xb4];
    hkVector4 m_kTranslationalVelocity;
    hkVector4 m_kAngularVelocity;
    char unkf0[0xfc - 0xf0];
    float m_limitA;
    char unk100[0x10c - 0x100];
    float m_limitC;
};

// @f3 0x009a9ba0 (community match, verified in this file)
bool FUN_00d28560(void* unused, char** items, int count, int offset)
{
    for (int i = count - 1; i >= 0; i--)
    {
        ContactBody* body = (ContactBody*)(*items + offset);
        float t0 = body->m_uiCommandId;
        float t = (1.0 < t0) ? 1.0f : t0;
        const float* lv = reinterpret_cast<const float*>(&body->m_kTranslationalVelocity);
        const float* av = reinterpret_cast<const float*>(&body->m_kAngularVelocity);
        float lin = lv[0] * lv[0] + lv[1] * lv[1] + lv[2] * lv[2];
        float ang = av[0] * av[0] + av[1] * av[1] + av[2] * av[2];
        float r = t * t * ang + lin;
        r = r * 0.25 - 0.010000000298023226;
        if ((body->m_qualityA & 0x7f) > (body->m_qualityC & 0x7f))
        {
            if (r > body->m_limitA)
            {
                return false;
            }
        }
        else if (r > body->m_limitC)
        {
            return false;
        }
        items++;
    }
    return true;
}


namespace fnv_00d31610 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c4c00;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setBroadcast3(const hkVector4q& v)
    {
        m_vComponents = _mm_shuffle_ps(v.m_vComponents, v.m_vComponents, 0xff);
    }
    __forceinline void addMul4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(a.m_vComponents, b.m_vComponents));
    }
    __forceinline void setNeg4(const hkVector4q& v)
    {
        m_vComponents = _mm_xor_ps(v.m_vComponents, DAT_010c4c00);
    }
    __forceinline void setNeg4b(const hkVector4q& v)
    {
        m_vComponents = _mm_xor_ps(DAT_010c4c00, v.m_vComponents);
    }
};

struct LinearCastVertex
{
    hkVector4q m_vContactPosition;
    hkVector4q m_direction;
    hkVector4q m_unk20;
};

struct GskVertexIds
{
    unsigned char m_numA : 4;
    unsigned char m_numB : 4;
};

struct GskCache
{
    unsigned short m_ausVertexIds[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    GskVertexIds m_counts;
    unsigned char m_unk304b;

    __forceinline void flip()
    {
        unsigned char lo = m_counts.m_numA;
        m_counts.m_numA = m_counts.m_numB;
        m_counts.m_numB = lo;

        unsigned char dimA = m_ucDimensionA;
        m_ucDimensionA = m_ucDimensionB;
        m_ucDimensionB = dimA;

        int last = m_ucDimensionA + m_ucDimensionB - 1;
        unsigned short t = m_ausVertexIds[0];
        m_ausVertexIds[0] = m_ausVertexIds[last];
        m_ausVertexIds[last] = t;

        if ((m_ucDimensionB & m_ucDimensionA) == 2)
        {
            unsigned short t1 = m_ausVertexIds[1];
            m_ausVertexIds[1] = m_ausVertexIds[2];
            m_ausVertexIds[2] = t1;
        }
    }
};

struct LinearCastState
{
    LinearCastVertex* m_kRayEnd;
    int m_unk04;
    int m_unk08;
    int m_unk0c;
    LinearCastVertex m_v000;
    LinearCastVertex m_v001;
    LinearCastVertex m_v002;
    LinearCastVertex m_v003;
    LinearCastVertex m_v004;
    LinearCastVertex m_v005;
    LinearCastVertex m_v006;
    LinearCastVertex m_v007;
    LinearCastVertex m_v008;
    LinearCastVertex m_v009;
    LinearCastVertex m_v010;
    LinearCastVertex m_v011;
    LinearCastVertex m_v012;
    LinearCastVertex m_v013;
    LinearCastVertex m_v014;
    LinearCastVertex m_v015;
    LinearCastVertex m_v016;
    LinearCastVertex m_v017;
    LinearCastVertex m_v018;
    LinearCastVertex m_v019;
    LinearCastVertex m_v020;
    LinearCastVertex m_v021;
    LinearCastVertex m_v022;
    LinearCastVertex m_v023;
    LinearCastVertex m_v024;
    LinearCastVertex m_v025;
    LinearCastVertex m_v026;
    LinearCastVertex m_v027;
    LinearCastVertex m_v028;
    LinearCastVertex m_v029;
    LinearCastVertex m_v030;
    LinearCastVertex m_v031;
    LinearCastVertex m_v032;
    LinearCastVertex m_v033;
    LinearCastVertex m_v034;
    LinearCastVertex m_v035;
    LinearCastVertex m_v036;
    LinearCastVertex m_v037;
    LinearCastVertex m_v038;
    LinearCastVertex m_v039;
    LinearCastVertex m_v040;
    LinearCastVertex m_v041;
    LinearCastVertex m_v042;
    LinearCastVertex m_v043;
    LinearCastVertex m_v044;
    LinearCastVertex m_v045;
    LinearCastVertex m_v046;
    LinearCastVertex m_v047;
    LinearCastVertex m_v048;
    LinearCastVertex m_v049;
    LinearCastVertex m_v050;
    LinearCastVertex m_v051;
    LinearCastVertex m_v052;
    LinearCastVertex m_v053;
    LinearCastVertex m_v054;
    LinearCastVertex m_v055;
    LinearCastVertex m_v056;
    LinearCastVertex m_v057;
    LinearCastVertex m_v058;
    LinearCastVertex m_v059;
    LinearCastVertex m_v060;
    LinearCastVertex m_v061;
    LinearCastVertex m_v062;
    LinearCastVertex m_v063;
    LinearCastVertex m_v064;
    LinearCastVertex m_v065;
    LinearCastVertex m_v066;
    LinearCastVertex m_v067;
    LinearCastVertex m_v068;
    LinearCastVertex m_v069;
    LinearCastVertex m_v070;
    LinearCastVertex m_v071;
    LinearCastVertex m_v072;
    LinearCastVertex m_v073;
    LinearCastVertex m_v074;
    LinearCastVertex m_v075;
    LinearCastVertex m_v076;
    LinearCastVertex m_v077;
    LinearCastVertex m_v078;
    LinearCastVertex m_v079;
    LinearCastVertex m_v080;
    LinearCastVertex m_v081;
    LinearCastVertex m_v082;
    LinearCastVertex m_v083;
    LinearCastVertex m_v084;
    LinearCastVertex m_v085;
    LinearCastVertex m_v086;
    LinearCastVertex m_v087;
    LinearCastVertex m_v088;
    LinearCastVertex m_v089;
    LinearCastVertex m_v090;
    LinearCastVertex m_v091;
    LinearCastVertex m_v092;
    LinearCastVertex m_v093;
    LinearCastVertex m_v094;
    LinearCastVertex m_v095;
    LinearCastVertex m_v096;
    LinearCastVertex m_v097;
    LinearCastVertex m_v098;
    LinearCastVertex m_v099;
    LinearCastVertex m_v100;
    LinearCastVertex m_v101;
    LinearCastVertex m_v102;
    LinearCastVertex m_v103;
    LinearCastVertex m_v104;
    LinearCastVertex m_v105;
    LinearCastVertex m_v106;
    LinearCastVertex m_v107;
    LinearCastVertex m_v108;
    LinearCastVertex m_v109;
    LinearCastVertex m_v110;
    LinearCastVertex m_v111;
    LinearCastVertex m_v112;
    LinearCastVertex m_v113;
    LinearCastVertex m_v114;
    LinearCastVertex m_v115;
    LinearCastVertex m_v116;
    LinearCastVertex m_v117;
    LinearCastVertex m_v118;
    LinearCastVertex m_v119;
    LinearCastVertex m_v120;
    LinearCastVertex m_v121;
    LinearCastVertex m_v122;
    LinearCastVertex m_v123;
    LinearCastVertex m_v124;
    LinearCastVertex m_v125;
    LinearCastVertex m_v126;
    LinearCastVertex m_v127;
    LinearCastVertex m_v128;
    LinearCastVertex m_v129;
    LinearCastVertex m_v130;
    LinearCastVertex m_v131;
    LinearCastVertex m_v132;
    LinearCastVertex m_v133;
    LinearCastVertex m_v134;
    LinearCastVertex m_v135;
    LinearCastVertex m_v136;
    LinearCastVertex m_v137;
    LinearCastVertex m_v138;
    LinearCastVertex m_v139;
    LinearCastVertex m_v140;
    LinearCastVertex m_v141;
    LinearCastVertex m_v142;
    LinearCastVertex m_v143;
    LinearCastVertex m_v144;
    LinearCastVertex m_v145;
    LinearCastVertex m_v146;
    LinearCastVertex m_v147;
    LinearCastVertex m_v148;
    LinearCastVertex m_v149;
    LinearCastVertex m_v150;
    LinearCastVertex m_v151;
    LinearCastVertex m_v152;
    LinearCastVertex m_v153;
    LinearCastVertex m_v154;
    LinearCastVertex m_v155;
    LinearCastVertex m_v156;
    LinearCastVertex m_v157;
    LinearCastVertex m_v158;
    LinearCastVertex m_v159;
    LinearCastVertex m_v160;
    LinearCastVertex m_v161;
    LinearCastVertex m_v162;
    LinearCastVertex m_v163;
    LinearCastVertex m_v164;
    LinearCastVertex m_v165;
    LinearCastVertex m_v166;
    LinearCastVertex m_v167;
    LinearCastVertex m_v168;
    LinearCastVertex m_v169;
    LinearCastVertex m_v170;
    LinearCastVertex m_v171;
    LinearCastVertex m_v172;
    LinearCastVertex m_v173;
    LinearCastVertex m_v174;
    LinearCastVertex m_v175;
    LinearCastVertex m_v176;
    LinearCastVertex m_v177;
    LinearCastVertex m_v178;
    LinearCastVertex m_v179;
    LinearCastVertex m_v180;
    LinearCastVertex m_v181;
    LinearCastVertex m_v182;
    LinearCastVertex m_v183;
    LinearCastVertex m_v184;
    LinearCastVertex m_v185;
    LinearCastVertex m_v186;
    LinearCastVertex m_v187;
    LinearCastVertex m_v188;
    LinearCastVertex m_v189;
    LinearCastVertex m_v190;
    LinearCastVertex m_v191;
    LinearCastVertex m_v192;
    LinearCastVertex m_v193;
    LinearCastVertex m_v194;
    LinearCastVertex m_v195;
    LinearCastVertex m_v196;
    LinearCastVertex m_v197;
    LinearCastVertex m_v198;
    LinearCastVertex m_v199;
    LinearCastVertex m_v200;
    LinearCastVertex m_v201;
    LinearCastVertex m_v202;
    LinearCastVertex m_v203;
    LinearCastVertex m_v204;
    LinearCastVertex m_v205;
    LinearCastVertex m_v206;
    LinearCastVertex m_v207;
    LinearCastVertex m_v208;
    LinearCastVertex m_v209;
    LinearCastVertex m_v210;
    LinearCastVertex m_v211;
    LinearCastVertex m_v212;
    LinearCastVertex m_v213;
    LinearCastVertex m_v214;
    LinearCastVertex m_v215;
    LinearCastVertex m_v216;
    LinearCastVertex m_v217;
    LinearCastVertex m_v218;
    LinearCastVertex m_v219;
    LinearCastVertex m_v220;
    LinearCastVertex m_v221;
    LinearCastVertex m_v222;
    LinearCastVertex m_v223;
    LinearCastVertex m_v224;
    LinearCastVertex m_v225;
    LinearCastVertex m_v226;
    LinearCastVertex m_v227;
    LinearCastVertex m_v228;
    LinearCastVertex m_v229;
    LinearCastVertex m_v230;
    LinearCastVertex m_v231;
    LinearCastVertex m_v232;
    LinearCastVertex m_v233;
    LinearCastVertex m_v234;
    LinearCastVertex m_v235;
    LinearCastVertex m_v236;
    LinearCastVertex m_v237;
    LinearCastVertex m_v238;
    LinearCastVertex m_v239;
    LinearCastVertex m_v240;
    LinearCastVertex m_v241;
    LinearCastVertex m_v242;
    LinearCastVertex m_v243;
    LinearCastVertex m_v244;
    LinearCastVertex m_v245;
    LinearCastVertex m_v246;
    LinearCastVertex m_v247;
    LinearCastVertex m_v248;
    LinearCastVertex m_v249;
    LinearCastVertex m_v250;
    LinearCastVertex m_v251;
    LinearCastVertex m_v252;
    LinearCastVertex m_v253;
    LinearCastVertex m_v254;
    LinearCastVertex m_v255;
    int m_unk3010;
    int m_unk3014;
    int m_unk3018;
    int m_unk301c;
    hkVector4q m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int m_unk3034;
    int m_unk3038;
    int m_unk303c;
    GskCache m_pAccessManager;
};

struct CastObj
{
    void __thiscall FUN_00d302d0(int a, int b, int c, LinearCastState& s);
    void __thiscall FUN_00d31610(int a1, int a2, int a3, LinearCastState& st);
};

}  // namespace fnv_00d31610

namespace fnv_00d36d60 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

class SimplexProcessor
{
  public:
    void FUN_00d369a0(int a, int b, int c, Simplex* s);
    void FUN_00d36d60(int a, int b, int c, Simplex* s);
};

}  // namespace fnv_00d36d60

namespace fnv_00d23380 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline float lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s);
        float r;
        _mm_store_ss(&r, s);
        return r;
    }
};

struct SortObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    hkVector4 m_vContactPosition;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    int m_priority;
};

struct SortEntry
{
    unsigned int m_data;
    SortObject* m_object;
    unsigned int m_extra;
};

struct SortList
{
    SortEntry m_entries[4];
    int m_iNumberOfEntries;
};

}  // namespace fnv_00d23380

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void operator delete(void*, void*) throw()
{}

struct FinishingFlag
{
    int m_bFinishing;
};

class S00d2c8a0_Base
{
  public:
    S00d2c8a0_Base(FinishingFlag flag);  // FUN_00d2c7e0
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class S00d2c8a0_Derived : public S00d2c8a0_Base
{
  public:
    S00d2c8a0_Derived(FinishingFlag flag) : S00d2c8a0_Base(flag)
    {}
    virtual void vf04();
    __m128 m_kScaleFactors;
};

namespace fnv_00d32850 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void FUN_00d324e0(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void FUN_00d32850(int a, int b, int c, Simplex* s);
};

}  // namespace fnv_00d32850

struct SortPair
{
    unsigned int key;
    unsigned int val;
};

// @fnv 0x00d36520
extern "C" void FUN_00d36520(SortPair* arr, int lo, int hi, unsigned int extra)
{
    int i;
    int j;
    __declspec(align(16)) SortPair pivot;
    __declspec(align(16)) SortPair tmp;

    for (;;)
    {
        i = lo;
        j = hi;
        pivot = arr[(lo + hi) >> 1];
        do
        {
            while (arr[i].key < pivot.key || (arr[i].key == pivot.key && arr[i].val < pivot.val))
            {
                ++i;
            }
            while (pivot.key < arr[j].key || (pivot.key == arr[j].key && pivot.val < arr[j].val))
            {
                --j;
            }
            if (j < i)
            {
                break;
            }
            if (j != i)
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            --j;
            ++i;
        } while (i <= j);
        if (lo < j)
        {
            FUN_00d36520(arr, lo, j, extra);
        }
        if (i >= hi)
        {
            break;
        }
        lo = i;
    }
}

struct hkpAgent3FuncsD367
{
    hkpAgent3FuncsD367()
    {
        m_bIsPredictive = false;
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction7 = 0;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};

void __cdecl FUN_00d367b0(hkpAgent3FuncsD367& kFuncs);

class hkpCollisionDispatcherD367
{
  public:
    void AddEntry(const hkpAgent3FuncsD367& kFuncs, int iTypeA, int iTypeB);
};

namespace fnv_00d36e80 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c44d0;

struct hkpCdBody;

struct hkVector4
{
    __m128 m_vComponents;
};

struct ShapeSweepParameters
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    hkVector4 m_path;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
};

class hkpCdPointCollector
{
  public:
    hkpCdPointCollector()
    {
        m_fEarlyOutDistance = 3.40282e+38f;
    }
    virtual void AddCdPoint(const void* point);
    float m_fEarlyOutDistance;
};

class hkpSymmetricAgentFlipCastCollector : public hkpCdPointCollector
{
  public:
    hkpSymmetricAgentFlipCastCollector(const hkVector4& path, hkpCdPointCollector& collector)
        : m_path(path), m_kCollector(collector)
    {}
    virtual void AddCdPoint(const void* point);
    hkVector4 m_path;
    hkpCdPointCollector& m_kCollector;
};

struct AgentBase
{
    void FUN_00d36960(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ShapeSweepParameters& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

struct Agent : AgentBase
{
    void FUN_00d36e80(const hkpCdBody& bodyA, const hkpCdBody& bodyB, const ShapeSweepParameters& input,
                      hkpCdPointCollector& collector, hkpCdPointCollector* startCollector);
};

}  // namespace fnv_00d36e80

namespace fnv_00d37c10 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void FUN_00d378e0(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void FUN_00d37c10(int a, int b, int c, Simplex* s);
};

}  // namespace fnv_00d37c10

struct hkpAgent3FuncsD398
{
    hkpAgent3FuncsD398()
    {
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
        m_pAgentFunction7 = 0;
        m_bIsPredictive = false;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};

class hkpCollisionDispatcherD398
{
  public:
    void AddEntry(const hkpAgent3FuncsD398& kFuncs, int iTypeA, int iTypeB);
};

void InitOutputDefaults();
void FUN_00d39130();
void ReleaseHandles();
void RemoveKeyFromTable();
void InsertIntoSlotArray();
void FUN_00d39090();
void FUN_00d39150();
void FUN_00d39390();

// @f3 0x009c29f0 (community match, verified in this file)
void FUN_009c2530();
void FUN_009c2240();
void FUN_009c2190();
void FUN_009c2220();
void __cdecl FUN_00d39840(hkpCollisionDispatcherD398* pkDispatcher)
{
    __declspec(align(16)) hkpAgent3FuncsD398 kFuncs;
    kFuncs.m_pCreateFunc = InitOutputDefaults;
    kFuncs.m_setCollisionQualityFunc = FUN_009c2530;
    kFuncs.m_pAgentFunction11 = FUN_009c2240;
    kFuncs.m_pAgentFunction3 = ReleaseHandles;
    kFuncs.m_pAgentFunction4 = RemoveKeyFromTable;
    kFuncs.m_pAgentFunction5 = InsertIntoSlotArray;
    kFuncs.m_createZeroContactFunc = FUN_009c2190;
    kFuncs.m_pAgent3DestroyFuncs = FUN_009c2220;
    pkDispatcher->AddEntry(kFuncs, 6, 4);
}


namespace fnv_00d3f500 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}

extern __m128 DAT_010c4c00;

struct SimplexVertex
{
    __m128 m_kPointA;
    __m128 m_kPointB;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct DimNibbles
{
    unsigned char m_ucLowNibble : 4;
    unsigned char m_ucHighNibble : 4;
};

struct Simplex
{
    SimplexVertex* m_kRayEnd;
    int unk04;
    int unk08;
    int unk0C;
    SimplexVertex m_kVertices[256];
    int unk3010;
    int unk3014;
    int unk3018;
    int unk301C;
    __m128 m_vHitNormal;
    float m_fClosestPointDistanceSquared;
    int unk3034;
    int unk3038;
    int unk303C;
    unsigned short m_ids[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
    DimNibbles m_dims;
};

struct AgentBase
{
    void FUN_00d3f080(int a, int b, int c, Simplex* s);
};

struct Agent : AgentBase
{
    void FUN_00d3f500(int a, int b, int c, Simplex* s);
};

}  // namespace fnv_00d3f500

namespace fnv_00d3fe90 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_set_ss(float);
    __m128 _mm_load_ss(const float*);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
    unsigned __int64 __rdtsc();
    void _ReadWriteBarrier();
}
extern unsigned int DAT_0126835c;
struct ProfileSample
{
    const char* name;
    unsigned int time, unk08;
};
struct ProfileBuffer
{
    unsigned int unk00;
    ProfileSample* current;
    unsigned int unk08;
    ProfileSample* end;
};
struct Vector
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct Matrix
{
    Vector c0, c1, c2, c3;
};
struct ShapeBase
{
    unsigned int unk00, unk04, unk08, unk0c;
    float radius;
};
struct Shape : ShapeBase
{
    unsigned int unk14, unk18, unk1c;
    __m128 halfExtents;
};
struct Body
{
    ShapeBase* shape;
    unsigned int unk04;
    Matrix* transform;
};
struct CollisionInput
{
    unsigned int unk00, unk04;
    float tolerance;
};
struct Params
{
    Body* a;
    Body* b;
    unsigned int unk08;
    CollisionInput* input;
    unsigned int unk10, unk14, unk18, unk1c;
    Matrix relative;
};
struct Processor
{
    const Body* a;
    const Body* b;
    CollisionInput* input;
    unsigned int manager;
    int output;
    const Matrix* worldA;
    const Matrix* worldB;
    unsigned int unk1c;
    Matrix relative;
    Vector halfA, halfB, tolerance, expandedA, expandedB;
    float scalarTolerance, constant;
    unsigned int unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    unsigned int unkE0, unkE4, unkE8, unkEC, unkF0, unkF4, unkF8, unkFC;
    unsigned int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128, unk12c;
    __forceinline Processor(const Body& aa, const Body& bb, CollisionInput* ii, unsigned int mm, int oo,
                            const Matrix& rr, const Matrix& wa, const Vector& ha, const Matrix& wb, const Vector& hb,
                            float tol)
    {
        a = &aa;
        b = &bb;
        input = ii;
        manager = mm;
        output = oo;
        worldA = &wa;
        worldB = &wb;
        Vector c0 = rr.c0;
        Vector c1 = rr.c1;
        Vector c2 = rr.c2;
        Vector c3 = rr.c3;
        relative.c0.quad = c0.quad;
        relative.c1.quad = c1.quad;
        relative.c2.quad = c2.quad;
        relative.c3.quad = c3.quad;
        halfA = ha;
        halfB = hb;
        __m128 t = _mm_set_ps1(tol);
        tolerance.quad = t;
        expandedA.quad = _mm_add_ps(tolerance.quad, ha.quad);
        expandedB.quad = _mm_add_ps(tolerance.quad, hb.quad);
        scalarTolerance = tol;
        constant = 0.01f;
    }
    void FUN_00db2960(unsigned char*);
};
}  // namespace fnv_00d3fe90

extern "C"
{
    __m128 _mm_set_ps1(float a);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    void _mm_store_ps(float* p, __m128 a);
}

extern "C" double fabs(double);

struct ClosestPointResult
{
    float distSq;
    float s;
    float t;
    float unk0C;
    __m128 p1;
    __m128 p2;
};

extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_xor_ps(__m128, __m128);

extern float DAT_0104da48;
extern __m128 DAT_010c44d0;
extern char DAT_010ce80c;

struct D2fVector4
{
    __declspec(align(16)) float m_vComponents[4];
    void setNeg4(const D2fVector4& v)
    {
        _mm_store_ps(m_vComponents, _mm_xor_ps(*(const __m128*)v.m_vComponents, DAT_010c44d0));
    }
};

struct __declspec(align(16)) D2fInput
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    D2fVector4 m_vec;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
};

struct D2fRayHitCollector
{
    virtual void CollectRayHit(const void* a, const void* b) = 0;
    float m_fHitDistance;
    D2fRayHitCollector() throw() : m_fHitDistance(DAT_0104da48)
    {}
};

struct __declspec(align(16)) D2fCollector : D2fRayHitCollector
{
    D2fVector4 m_vec;
    void* m_user;

    D2fCollector(const D2fVector4& v, void* user) throw() : m_vec(v), m_user(user)
    {}
    virtual void CollectRayHit(const void* a, const void* b);
};

struct D2fWorld
{
    void FUN_00d315a0(int a, int b, D2fInput* in, D2fCollector* c1, D2fCollector* c2);
    void FUN_00d2f460(int a1, int a2, const D2fInput* a3, int a4, void* a5);
};

namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int8 m128_i8[16];
    __int16 m128_i16[8];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int8 m128_u8[16];
    unsigned __int16 m128_u16[8];
    unsigned __int32 m128_u32[4];
};
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
}
}

class S00d2c910_Base
{
  public:
    S00d2c910_Base(void* a, int b);  // FUN_00d2b260
    virtual void vf00();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

class FUN_00d2c910 : public S00d2c910_Base
{
  public:
    FUN_00d2c910(void* a, int b);
    virtual void vf00();
    N::__m128 m_kScaleFactors;
};
