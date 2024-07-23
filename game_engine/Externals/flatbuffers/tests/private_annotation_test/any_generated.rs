// automatically generated by the FlatBuffers compiler, do not modify
// @generated
extern crate alloc;
extern crate flatbuffers;
use alloc::boxed::Box;
use alloc::string::{String, ToString};
use alloc::vec::Vec;
use core::mem;
use core::cmp::Ordering;
use self::flatbuffers::{EndianScalar, Follow};
use super::*;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
pub const ENUM_MIN_ANY: u8 = 0;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
pub const ENUM_MAX_ANY: u8 = 2;
#[deprecated(since = "2.0.0", note = "Use associated constants instead. This will no longer be generated in 2021.")]
#[allow(non_camel_case_types)]
pub const ENUM_VALUES_ANY: [Any; 3] = [
  Any::NONE,
  Any::Game,
  Any::Annotations,
];

#[derive(Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash, Default)]
#[repr(transparent)]
pub(crate) struct Any(pub u8);
#[allow(non_upper_case_globals)]
impl Any {
  pub const NONE: Self = Self(0);
  pub const Game: Self = Self(1);
  pub const Annotations: Self = Self(2);

  pub const ENUM_MIN: u8 = 0;
  pub const ENUM_MAX: u8 = 2;
  pub const ENUM_VALUES: &'static [Self] = &[
    Self::NONE,
    Self::Game,
    Self::Annotations,
  ];
  /// Returns the variant's name or "" if unknown.
  pub fn variant_name(self) -> Option<&'static str> {
    match self {
      Self::NONE => Some("NONE"),
      Self::Game => Some("Game"),
      Self::Annotations => Some("Annotations"),
      _ => None,
    }
  }
}
impl core::fmt::Debug for Any {
  fn fmt(&self, f: &mut core::fmt::Formatter) -> core::fmt::Result {
    if let Some(name) = self.variant_name() {
      f.write_str(name)
    } else {
      f.write_fmt(format_args!("<UNKNOWN {:?}>", self.0))
    }
  }
}
impl<'a> flatbuffers::Follow<'a> for Any {
  type Inner = Self;
  #[inline]
  unsafe fn follow(buf: &'a [u8], loc: usize) -> Self::Inner {
    let b = flatbuffers::read_scalar_at::<u8>(buf, loc);
    Self(b)
  }
}

impl flatbuffers::Push for Any {
    type Output = Any;
    #[inline]
    unsafe fn push(&self, dst: &mut [u8], _written_len: usize) {
        flatbuffers::emplace_scalar::<u8>(dst, self.0);
    }
}

impl flatbuffers::EndianScalar for Any {
  type Scalar = u8;
  #[inline]
  fn to_little_endian(self) -> u8 {
    self.0.to_le()
  }
  #[inline]
  #[allow(clippy::wrong_self_convention)]
  fn from_little_endian(v: u8) -> Self {
    let b = u8::from_le(v);
    Self(b)
  }
}

impl<'a> flatbuffers::Verifiable for Any {
  #[inline]
  fn run_verifier(
    v: &mut flatbuffers::Verifier, pos: usize
  ) -> Result<(), flatbuffers::InvalidFlatbuffer> {
    use self::flatbuffers::Verifiable;
    u8::run_verifier(v, pos)
  }
}

impl flatbuffers::SimpleToVerifyInSlice for Any {}
pub(crate) struct AnyUnionTableOffset {}

#[allow(clippy::upper_case_acronyms)]
#[non_exhaustive]
#[derive(Debug, Clone, PartialEq)]
pub(crate) enum AnyT {
  NONE,
  Game(Box<GameT>),
  Annotations(Box<AnnotationsT>),
}
impl Default for AnyT {
  fn default() -> Self {
    Self::NONE
  }
}
impl AnyT {
  pub fn any_type(&self) -> Any {
    match self {
      Self::NONE => Any::NONE,
      Self::Game(_) => Any::Game,
      Self::Annotations(_) => Any::Annotations,
    }
  }
  pub fn pack<'b, A: flatbuffers::Allocator + 'b>(&self, fbb: &mut flatbuffers::FlatBufferBuilder<'b, A>) -> Option<flatbuffers::WIPOffset<flatbuffers::UnionWIPOffset>> {
    match self {
      Self::NONE => None,
      Self::Game(v) => Some(v.pack(fbb).as_union_value()),
      Self::Annotations(v) => Some(v.pack(fbb).as_union_value()),
    }
  }
  /// If the union variant matches, return the owned GameT, setting the union to NONE.
  pub fn take_game(&mut self) -> Option<Box<GameT>> {
    if let Self::Game(_) = self {
      let v = core::mem::replace(self, Self::NONE);
      if let Self::Game(w) = v {
        Some(w)
      } else {
        unreachable!()
      }
    } else {
      None
    }
  }
  /// If the union variant matches, return a reference to the GameT.
  pub fn as_game(&self) -> Option<&GameT> {
    if let Self::Game(v) = self { Some(v.as_ref()) } else { None }
  }
  /// If the union variant matches, return a mutable reference to the GameT.
  pub fn as_game_mut(&mut self) -> Option<&mut GameT> {
    if let Self::Game(v) = self { Some(v.as_mut()) } else { None }
  }
  /// If the union variant matches, return the owned AnnotationsT, setting the union to NONE.
  pub fn take_annotations(&mut self) -> Option<Box<AnnotationsT>> {
    if let Self::Annotations(_) = self {
      let v = core::mem::replace(self, Self::NONE);
      if let Self::Annotations(w) = v {
        Some(w)
      } else {
        unreachable!()
      }
    } else {
      None
    }
  }
  /// If the union variant matches, return a reference to the AnnotationsT.
  pub fn as_annotations(&self) -> Option<&AnnotationsT> {
    if let Self::Annotations(v) = self { Some(v.as_ref()) } else { None }
  }
  /// If the union variant matches, return a mutable reference to the AnnotationsT.
  pub fn as_annotations_mut(&mut self) -> Option<&mut AnnotationsT> {
    if let Self::Annotations(v) = self { Some(v.as_mut()) } else { None }
  }
}
