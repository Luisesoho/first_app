class Job < ActiveRecord::Base
  attr_accessible :begin, :duration, :end, :fez, :name, :sez
  validates :duration, presence: true, :numericality => { :greater_than => 0}
  validates :name, presence: true, length: {maximum: 20},  uniqueness: { case_sensitive: false }
  validates :fez, presence: true, :numericality => { :greater_than => 0}
  validates :sez, presence: true, :numericality => { :greater_than => 0}
end
